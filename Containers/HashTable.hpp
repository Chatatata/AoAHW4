//
//  HashTable.hpp
//  AoAHW4
//
//  Created by Buğra Ekuklu on 7.12.2016.
//  Copyright © 2016 Buğra Ekuklu. All rights reserved.
//

#pragma once

#include "../PrefixHeader.pch"

namespace Container {
    
    class HashTable {
    public:
        HashTable(UInt64 size);
        HashTable(const HashTable &object);
        
        virtual ~HashTable();
        
        const UInt64 size = 0LL;
        
        UInt64 hashValue(String key);
        UInt64 insert(String key);
        Boolean retrieve(String key) noexcept;
        UInt64 findIndex(String key);
        void remove(String key);
        
        UInt64 getLastCollisionCount() const noexcept;
        UInt64 getTotalCollisionCount() const noexcept;
    
    private:
    public:
        String *data = nullptr;
        UInt64 count = 0LL;
        UInt64 lastCollisionCount = 0LL;
        UInt64 totalCollisionCount = 0LL;
    };
}
