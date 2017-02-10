//
//  Array.cpp
//  AoAHW4
//
//  Created by Buğra Ekuklu on 24.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#include "Array.hpp"

#include <cstring>

template <typename T>
Container::Array<T>::Array()
: data(new T[initialLength]()), length(0)
{
    //  Blank implementation
}

template <typename T>
Container::Array<T>::Array(const Array &other)
: data(new T[initialLength]()), length(other.length)
{
    std::memcpy(this->data, other.data, sizeof(T) * other.length);
}

template <typename T>
Container::Array<T> &
Container::Array<T>::operator = (const Array &other)
{
    if (this != &other) {
        for (UInt64 i = 0; i < other.length; ++i) {
            data[i] = T(other.data[i]);
        }
        
        length = other.length;
        
        return *this;
    } else {
        return *this;
    }
}

template <typename T>
inline
T &
Container::Array<T>::objectAtIndex(const UInt64 index) const
{
    return data[index];
}

template <typename T>
inline
T &
Container::Array<T>::operator [] (const UInt64 index) const
{
    return objectAtIndex(index);
}

template <typename T>
inline
void
Container::Array<T>::append(const T &object) noexcept
{
    data[length] = object;
    
    length += 1;
}

template <typename T>
inline
UInt64
Container::Array<T>::getLength() const noexcept
{
    return length;
}

template <typename T>
inline
void
Container::Array<T>::setLength(const UInt64 length) noexcept
{
    this->length = length;
}








































