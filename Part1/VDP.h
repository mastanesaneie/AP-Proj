#pragma once

#include <stdexcept>
#include <utility>

template <typename T>
class VDP                    
{
public:
    VDP(unsigned int initialCapacity = 0);
    ~VDP();

    void push_back(const T& item);
    void insert(const T& item, unsigned int position);
    void remove(unsigned int position);
    unsigned int size() const;
    T& operator[](unsigned int position);
    const T& operator[](unsigned int position) const;

protected:
    void resize(unsigned int newCapacity);

private:
    T** data = nullptr;
    unsigned int capacity = 0;
    unsigned int count = 0;
};

template <typename T>
VDP<T>::VDP(unsigned int initialCapacity)
{
    resize(initialCapacity);
}

template <typename T>
VDP<T>::~VDP()
{
    for (unsigned int i = 0; i < count; ++i)
    {
        delete data[i];
    }
    delete[] data;
}

template <typename T>
void VDP<T>::push_back(const T& item)
{
    if (count == capacity)
        resize(capacity > 0 ? capacity * 2 : 1);

    data[count] = new T(item);
    ++count;
}

template <typename T>
void VDP<T>::insert(const T& item, unsigned int position)
{
    if (position > count)
        throw std::out_of_range("Position out of range");

    if (count == capacity)
        resize(capacity > 0 ? capacity * 2 : 1);

    for (unsigned int i = count; i > position; --i)
    {
        data[i] = data[i - 1];
    }

    data[position] = new T(item);
    ++count;
}

template <typename T>
void VDP<T>::remove(unsigned int position)
{
    if (position >= count)
        throw std::out_of_range("Position out of range");

    delete data[position];

    for (unsigned int i = position; i < count - 1; ++i)
    {
        data[i] = data[i + 1];
    }

    --count;
}

template <typename T>
unsigned int VDP<T>::size() const
{
    return count;
}

template <typename T>
T& VDP<T>::operator[](unsigned int position)
{
    if (position >= count)
        throw std::out_of_range("Position out of range");

    return *data[position];
}

template <typename T>
const T& VDP<T>::operator[](unsigned int position) const
{
    if (position >= count)
        throw std::out_of_range("Position out of range");

    return *data[position];
}

template <typename T>
void VDP<T>::resize(unsigned int newCapacity)
{
    T** temp = new T*[newCapacity];
    unsigned int limit = (newCapacity < count) ? newCapacity : count;

    for (unsigned int i = 0; i < limit; ++i)
    {
        temp[i] = data[i];
    }

    delete[] data;
    data = temp;
    capacity = newCapacity;
    if (newCapacity < count)
        count = newCapacity;
}
