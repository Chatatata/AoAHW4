//
//  HashTable.cpp
//  AoAHW4
//
//  Created by Buğra Ekuklu on 7.12.2016.
//  Copyright © 2016 Buğra Ekuklu. All rights reserved.
//

#include "HashTable.hpp"

#include <cstdlib>
#include <cstring>

#include "../ErrorHandling/RangeException.hpp"
#include "../ErrorHandling/DuplicateValueException.hpp"
#include "../ErrorHandling/BufferOverrunException.hpp"
#include "../ErrorHandling/BadAllocationException.hpp"

using Container::HashTable;

HashTable::HashTable(UInt64 size)
: size(size), data(new String[size]())
{
    if (size == 0) {
        throw RangeException(size);
    }
}

HashTable::HashTable(const HashTable &object)
: size(object.size), data(new String[object.size]())
{
    for (UInt64 i = 0; i < object.size; ++i) {
        data[i] = String(object.data[i]);
    }
}

HashTable::~HashTable()
{
    delete [] data;
}

UInt64
HashTable::hashValue(String key)
{
    UInt64 result = 1LL;
    
    for (UInt64 i = 0; i < key.size(); i++) {
        result *= static_cast<UInt8>(key.data()[i]);
        result %= size;
    }
    
    return result;
}

void
HashTable::insert(String key)
{
    if (count < size) {
        auto hash = hashValue(key);
        
        while (1) {
            if (data[hash] == key) {
                throw DuplicateValueException();
            } else if (data[hash] == "" || data[hash] == "*") {
                data[hash] = String(key);
                
                break;
            } else {
                hash += 1;
                collisionCount += 1;
            }
        }
        
        count += 1;
    } else {
        throw BadAllocationException(size);
    }
}

Boolean
HashTable::retrieve(String key) noexcept
{
    auto hash = hashValue(key);
    
    if (hash > size) throw RangeException(hash);
    
    for (UInt64 i = hash; i < size; ++i) {
        if (data[i] == key) {
            return true;
        } else if (data[i] == "") {
            return false;
        }
    }
    
    throw BufferOverrunException();
}

void
HashTable::remove(String key)
{
    auto hash = hashValue(key);
    
    for (UInt64 i = hash; i < size; ++i) {
        if (data[i] == key) {
            data[i] = "*";
            
            return;
        } else if (data[i] == "") {
            throw RangeException(i);
        }
    }
    
    throw BufferOverrunException();
}

UInt64
HashTable::getCollisionCount() const noexcept
{
    return collisionCount;
}
