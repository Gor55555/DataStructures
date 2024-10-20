#include "Vector.hpp"

namespace STD
{
	template <typename T>
	Vector<T>::Vector() :size(0), capacity(0), element(nullptr) {}

	template <typename T>
	Vector<T>::Vector(size_t size_) :size(size_), capacity(size_), element(new T[capacity]{}) {}
	
	template <typename T>
	Vector<T>::Vector(size_t size_, const T& value) :size(size_), capacity(size_), element(new T[capacity])
	{
		for (size_t i = 0; i < size; ++i)
		{
			element[i] = value;
		}
	}

	template <typename T>
	Vector<T>::Vector(const Vector& other) :capacity(other.capacity), size(other.size), element(new T[capacity])
	{
		for (size_t i = 0; i < size; ++i)
		{
			element[i] = other.element[i];
		}
	}

	template <typename T>
	Vector<T>& Vector<T>::operator=(const Vector& other)
	{
		if (this == &other)
		{
			return *this;
		}

		delete[] element;

		capacity = other.capacity;
		size = other.size;
		element = new T[capacity];

		for (size_t i = 0; i < size; ++i)
		{
			element[i] = other.element[i];
		}

		return *this;
	}

	template <typename T>
	Vector<T> Vector<T>::operator+(const Vector& other)
	{
		Vector result;
		result.size = size + other.size;
		result.capacity = capacity + other.capacity;
		result.element = new T[result.capacity];

		for (size_t i = 0; i < size; ++i)
		{
			result.element[i] = element[i];
		}
		for (size_t i = 0; i < other.size; ++i)
		{
			result.element[size + i] = other.element[i];
		}

		return result;
	}
	
	template <typename T>
	Vector<T>::Vector(Vector&& other) noexcept
		:size(other.size), capacity(other.capacity), element(other.element)
	{
		other.size = 0;
		other.capacity = 0;
		other.element = nullptr;
	}

	template <typename T>
	Vector<T>& Vector<T>::operator=(Vector&& other) noexcept
	{
		if (this == &other)
		{
			return *this;
		}

		delete[] element;

		size = other.size;
		capacity = other.capacity;
		element = other.element;

		other.size = 0;
		other.capacity = 0;
		other.element = nullptr;

		return *this;
	}

	template <typename T>
	Vector<T>::~Vector()
	{
		delete[] element;
	}
 
	template <typename T>
	size_t Vector<T>::Size() const
	{
		return size;
	}
	
	template <typename T>
	size_t Vector<T>::Capacity() const
	{
		return capacity;
	}

	template <typename T>
	bool Vector<T>::Empty() const
	{
		return Size() == 0;
	}

	template <typename T>
	void Vector<T>::Reserve(size_t new_capacity)
	{
		if (new_capacity > capacity)
		{
			T* new_element = new T[new_capacity];
			for (size_t i = 0; i < size; ++i)
			{
				new_element[i] = element[i];
			}
			delete[] element;
			element = new_element;
			capacity = new_capacity;
		}
	}

	template <typename T>
	void Vector<T>::Push_Back(const T& value)
	{
		if (size == capacity)
		{
			if (capacity == 0)
			{
				Reserve(1);
			}
			else
			{
				Reserve(capacity * 2);
			}
		}
		element[size++] = value;
	}

	template <typename T>
	void Vector<T>::Pop_Back()
	{
		if (size > 0)
		{
			size--;
		}
	}

	template <typename T>
	T& Vector<T>::At(size_t index)
	{
		if (index < size)
		{
			return element[index];
		}
		throw std::out_of_range("Index out of range");
	}

	template <typename T>
	const T& Vector<T>::At(size_t index) const
	{
		if (index < size)
		{
			return element[index];
		}
		throw std::out_of_range("Index out of range");
	}
	template <typename T>
	T& Vector<T>::operator[](size_t index)
	{
		return element[index];
	}

	template <typename T>
	const T& Vector<T>::operator[](size_t index) const
	{
		return element[index];
	}

	template <typename T>
	void Vector<T>::Clear()
	{
		size = 0;
	}
}

