#include <iostream>
#include "Vector.hpp"

int main()
{
    /*_______ Here you can test the following operations for the Vector _______*/

    // Default constructor: 
    STD::Vector<int> vec1;
    std::cout << "Default constructor:\n";

    // Parameterized constructor: 
    STD::Vector<int> v2(5); 
    std::cout << "Parameterized constructor:\n";
    for (size_t i = 0; i < v2.Size(); ++i)
    {
        std::cout << v2[i] << " ";
    }
    std::cout << "\n";

    // Parameterized and fill constructor: 
    STD::Vector<int> v3(5, 10);
    std::cout << "Parameterized and fill constructor:\n";
    for (size_t i = 0; i < v3.Size(); ++i)
    {
        std::cout << v3[i] << " ";
    }
    std::cout << "\n";

    // Copy Constructor(Deep Copy): 
    STD::Vector<int> v4(v3);
    std::cout << "Copy Constructor(Deep Copy):\n";
    for (size_t i = 0; i < v4.Size(); ++i)
    {
        std::cout << v4[i] << " ";
    }
    std::cout << "\n";

    // Copy Assignment Operator:
    STD::Vector<int> v5;
    v5 = v4;
    std::cout << "Copy Assignment Operator:\n";
    for (size_t i = 0; i < v5.Size(); ++i)
    {
        std::cout << v5[i] << " ";
    }
    std::cout << "\n";

    // Addition Operator Overloading: 
    STD::Vector<int> v6;
    v6 = v5 + v4;
    std::cout << "Addition Operator Overloading:\n";
    for (size_t i = 0; i < v6.Size(); ++i)
    {
        std::cout << v6[i] << " ";
    }
    std::cout << "\n";

    // Move Constructor:
    STD::Vector<int> v7(std::move(v6));
    std::cout << "Move Constructor:\n";
    for (size_t i = 0; i < v7.Size(); ++i) {
        std::cout << v7[i] << " "; 
    }
    std::cout << "\n";

    // Move Assignment Operator:
    STD::Vector<int> v8;
    v8 = std::move(v7); 
    std::cout << "Move Assignment Operator:\n";
    for (size_t i = 0; i < v8.Size(); ++i) {
        std::cout << v8[i] << " "; 
    }
    std::cout << "\n\n";

    // Push_Back:
    STD::Vector<int> vec;
    vec.Push_Back(1);
    vec.Push_Back(2);
    vec.Push_Back(3);
    vec.Push_Back(4);

    // Pop_Back:
    vec.Pop_Back();

    // At:
    for (size_t i = 0; i < vec.Size(); ++i) 
    {
        std::cout << vec.At(i) << " ";
    }
    std::cout << "\n";

    // Iterator operations:
    for (STD::Vector<int>::Iterator it = vec.Begin(); it != vec.End(); ++it) 
    {
        std::cout << *it << " "; 
    }

}