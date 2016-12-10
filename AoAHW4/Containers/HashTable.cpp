//
//  HashTable.cpp
//  AoAHW4
//
//  Created by Buğra Ekuklu on 7.12.2016.
//  Copyright © 2016 Buğra Ekuklu. All rights reserved.
//

#include "HashTable.hpp"

#include <cstdlib>

using Container::HashTable;

HashTable::HashTable(UInt64 size)
: size(size), data(new String[UINT32_MAX]())
{
    if (size == 0) {
        throw "Range error.";
    }
}

UInt64
HashTable::hashValue(String key)
{
    UInt64 result = 0LL;
    
    for (UInt64 i = 0; i < key.size(); i++) {
        result *= static_cast<UInt8>(key.data()[i]);
        result %= count;
    }
    
    return result;
}

void
HashTable::insert(String key) noexcept
{
    auto hash = hashValue(key);
    
    while (1) {
        if (data[hash] != "") {
            data[hash] = key;
            
            break;
        } else {
            hash += 1;
        }
    }
    
    
}

Boolean
HashTable::retrieve(String key) noexcept
{
    
}

Boolean
HashTable::remove(String key) noexcept
{
    
}
