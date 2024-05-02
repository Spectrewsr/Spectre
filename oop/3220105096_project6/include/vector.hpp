#ifndef _VEC_HPP_
#define _VEC_HPP_
#include<iostream>
#include<memory>
#include<utility>

template <class T>
class Vector {
public:
    Vector();                      // creates an empty vector
    Vector(int size);              // creates a vector for holding 'size' elements
    Vector(const Vector& r);       // the copy ctor
    ~Vector();                     // destructs the vector 
    T& operator[](int index);      // accesses the specified element without bounds checking
    T& at(int index);              // accesses the specified element, throws an exception of
                                    // type 'std::out_of_range' when index <0 or >=m_nSize
    int size() const;              // return the size of the container
    void push_back(const T& x);    // adds an element to the end 
    void clear();                  // clears the contents
    bool empty() const;            // checks whether the container is empty 
private:
    void inflate();                // expand the storage of the container to a new capacity,
                                    // e.g. 2*m_nCapacity
    T *m_pElements;                // pointer to the dynamically allocated storage
    int m_nSize;                   // the number of elements in the container
    int m_nCapacity;               // the total number of elements that can be held in the
                                    // allocated storage
    typedef T* iterator;
    typedef long long ll;

    iterator ele, mem_free,mem_end;

};



template <class T>
Vector<T>::Vector()
{
    m_nSize = 0;                   
    m_nCapacity = 1;             
    m_pElements = new T[m_nCapacity]; 
}

template <class T>
Vector<T>::Vector(int size)
{
    
    this->m_nSize = size;
    this->m_nCapacity = size;
    this->m_pElements = new T[size];
}

template <class T>
Vector<T>::Vector(const Vector& r)
{
    this->m_nSize = r.m_nSize;
    this->m_nCapacity = r.m_nCapacity;
    this->m_pElements = new T[m_nCapacity];
    for ( int i = 0; i < m_nSize; ++i )
    {
        m_pElements[i] = r.m_pElements[i];
    }
}

template <class T>
Vector<T>::~Vector()
{

    delete[] m_pElements;
    m_nCapacity = 0;
    m_nSize = 0;
    m_pElements = nullptr;
}

template<class T>
int Vector<T>::size() const
{
    return m_nSize;
}

template <class T>
T& Vector<T>::operator[](int index) 
{
    return m_pElements[index];
}

template <class T>
T& Vector<T>::at(int index) 
{
    if (index < 0 || index >= m_nSize) 
    {
        throw std::out_of_range("Index out of range");
    }
    return m_pElements[index];
}

template <class T>
void Vector<T>::inflate()
{
    if(m_nCapacity == 0)
    {
        m_nCapacity = 1;
    }
    else
    {
        m_nCapacity *= 2 ;
    }

    T* newElements = new T[m_nCapacity];
    for (int i = 0; i < m_nSize; i++) 
    {
        newElements[i] = m_pElements[i];
    }

    delete[] m_pElements;
    m_pElements = newElements;
}

template <class T>
bool Vector<T>::empty() const
{
    return m_nSize == 0;
}

template <class T>
void Vector<T>::clear()
{
    m_nCapacity = 0;
    m_nSize = 0;
    m_pElements = nullptr;
    delete[] m_pElements;
}

template <class T>
void Vector<T>::push_back(const T& x)
{
    if (m_nSize == m_nCapacity) 
    {
        inflate();
    }
    m_pElements[m_nSize++] = x;
}

#endif