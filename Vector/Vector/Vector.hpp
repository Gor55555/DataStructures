#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace STD
{
	template <typename T>
	class Vector
	{
	private:
		size_t size;
		size_t capacity;
		T* element;

	public:
		Vector();                                      //Default Constructor
		Vector(size_t size_);                          //Parameterized Constructor
		Vector(size_t size_, const T& value);          //Parameterized and Fill Constructor
		Vector(const Vector& other);                   //Copy Constructor(Deep Copy)
		Vector& operator=(const Vector& other);        //Copy Assignment Operator
		Vector operator+(const Vector& other);         //Addition Operator Overloading
		Vector(Vector&& other) noexcept;               //Move constructor
		Vector& operator=(Vector&& other) noexcept;    //Move Assignment Operator
		~Vector();                                     //Destructor

		size_t Size() const;
		size_t Capacity() const;
		bool Empty() const;
		void Reserve(size_t);
		void Clear();

		void Push_Back(const T& value);
		void Pop_Back();

		T& At(size_t index);
		const T& At(size_t index) const;
		T& operator[](size_t index);
		const T& operator[](size_t index) const;
	
		class Iterator
		{
		private:
			T* ptr;
		public:
			Iterator(T* ptr);
			T& operator*();
			Vector::Iterator& operator++(); 
			Iterator operator++(int); 
			bool operator==(const Iterator& other) const;
			bool operator!=(const Iterator& other) const;
		};
		Iterator Begin();
		Iterator End();
	};
}

#include "MyVector.ipp"
#include "MyIterator.ipp"

#endif 
