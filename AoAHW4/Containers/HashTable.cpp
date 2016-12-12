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

UInt64
HashTable::insert(String key)
{
    lastCollisionCount = 0LL;
    
    if (count < size) {
        for (auto hash = hashValue(key); hash < size; hash++) {
            if (data[hash] == key) {
                throw DuplicateValueException();
            } else if (data[hash] == "" || data[hash] == "*") {
                data[hash] = String(key);
                count += 1;
                
                totalCollisionCount += lastCollisionCount;
                
                return hash;
            } else {
                lastCollisionCount += 1;
            }
        }
        
        throw BadAllocationException(size);
    } else {
        throw BadAllocationException(size);
    }
}

Boolean
HashTable::retrieve(String key) noexcept
{
    auto hash = hashValue(key);
    lastCollisionCount = 0LL;
    
    if (hash > size) throw RangeException(hash);
    
    for (UInt64 i = hash; i < size; ++i) {
        if (data[i] == key) {
            totalCollisionCount += lastCollisionCount;
            
            return true;
        } else if (data[i] == "") {
            totalCollisionCount += lastCollisionCount;
            
            return false;
        }
        
        lastCollisionCount += 1LL;
    }
    
    totalCollisionCount += lastCollisionCount;
    
    return false;
}

UInt64
HashTable::findIndex(String key)
{
    auto hash = hashValue(key);
    lastCollisionCount = 0LL;
    
    if (hash > size) throw RangeException(hash);
    
    for (UInt64 i = hash; i < size; ++i) {
        if (data[i] == key) {
            totalCollisionCount += lastCollisionCount;
            
            return i;
        } else if (data[i] == "") {
            totalCollisionCount += lastCollisionCount;
            
            throw RangeException(size);
        }
        
        lastCollisionCount += 1LL;
    }
    
    totalCollisionCount += lastCollisionCount;
    
    throw RangeException(size);
}

void
HashTable::remove(String key)
{
    auto hash = hashValue(key);
    lastCollisionCount = 0LL;
    
    for (UInt64 i = hash; i < size; ++i) {
        if (data[i] == key) {
            data[i] = "*";
            
            totalCollisionCount += lastCollisionCount;
            
            return;
        } else if (data[i] == "") {
            totalCollisionCount += lastCollisionCount;
            
            throw RangeException(i);
        }
        
        lastCollisionCount += 1LL;
    }
    
    throw RangeException(size);
}

UInt64
HashTable::getLastCollisionCount() const noexcept
{
    return lastCollisionCount;
}

UInt64
HashTable::getTotalCollisionCount() const noexcept
{
    return totalCollisionCount;
}
