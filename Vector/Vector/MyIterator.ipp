#include "Vector.hpp"

namespace STD
{
    template <typename T>
    Vector<T>::Iterator::Iterator(T* ptr) : ptr(ptr) {}

    template <typename T>
    T& Vector<T>::Iterator::operator*()
    {
        return *ptr; 
    }

    template <typename T>
    typename Vector<T>::Iterator& Vector<T>::Iterator::operator++()
    {
        ++ptr;  
        return *this;  
    }

    template <typename T>
    typename Vector<T>::Iterator Vector<T>::Iterator::operator++(int)
    {
        Iterator temp = *this;  
        ++(*this);  
        return temp;  
    }

    template <typename T>
    bool Vector<T>::Iterator::operator==(const Iterator& other) const
    {
        return ptr == other.ptr;  
    }

    template <typename T>
    bool Vector<T>::Iterator::operator!=(const Iterator& other) const
    {
        return ptr != other.ptr; 
    }

    template <typename T>
    typename Vector<T>::Iterator Vector<T>::Begin()
    {
        return Iterator(element);  
    }


    template <typename T>
    typename Vector<T>::Iterator Vector<T>::End()
    {
        return Iterator(element + size);
    }

}