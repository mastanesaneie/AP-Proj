#pragma once

#include <stdexcept>
#include <utility>

template <typename T>
class Vector
{
public:
    Vector(unsigned int initialCapacity = 0);
    ~Vector();

    void push_back(const T& item);
    void insert(const T& item, unsigned int position);
    void remove(unsigned int position);
    unsigned int size() const;
    T& operator[](unsigned int position);
    const T& operator[](unsigned int position) const;

protected:
    void resize(unsigned int newCapacity);

private:
    T* data = nullptr;
    unsigned int capacity = 0;
    unsigned int count = 0;
};


template <typename T>
Vector<T>::Vector(unsigned int initialCapacity)
{
    resize(initialCapacity);
}


template <typename T>
Vector<T>::~Vector()
{
    delete[] data;
}


template <typename T>
void Vector<T>::push_back(const T& item)
{
    if (count == capacity)
        resize(capacity > 0 ? capacity * 2 : 1);

    data[count] = item;
    ++count;
}


template <typename T>
void Vector<T>::insert(const T& item, unsigned int position)
{
    if (position > count)
        throw std::out_of_range("Position out of range");

    if (count == capacity)
        resize(capacity > 0 ? capacity * 2 : 1);

    for (unsigned int i = count; i > position; --i)
    {
        data[i] = data[i - 1];
    }
    data[position] = item;
    ++count;
}


template <typename T>
void Vector<T>::remove(unsigned int position)
{
    if (position >= count)
        throw std::out_of_range("Position out of range");

    for (unsigned int i = position; i < count - 1; ++i)
    {
        data[i] = data[i + 1];
    }
    --count;
}


template <typename T>
unsigned int Vector<T>::size() const
{
    return count;
}


template <typename T>
T& Vector<T>::operator[](unsigned int position)
{
    if (position >= count)
        throw std::out_of_range("Position out of range");

    return data[position];
}


template <typename T>
const T& Vector<T>::operator[](unsigned int position) const
{
    if (position >= count)
        throw std::out_of_range("Position out of range");

    return data[position];
}


template <typename T>
void Vector<T>::resize(unsigned int newCapacity)
{
    T* temp = new T[newCapacity];
    unsigned int limit = (newCapacity < count) ? newCapacity : count;

    for (unsigned int i = 0; i < limit; ++i)
    {
        temp[i] = std::move(data[i]);
    }

    delete[] data;
    data = temp;
    capacity = newCapacity;
    if (newCapacity < count)
        count = newCapacity;
}


