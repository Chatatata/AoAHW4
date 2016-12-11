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
        void insert(String key);
        Boolean retrieve(String key) noexcept;
        void remove(String key);
        
        UInt64 getCollisionCount() const noexcept;
    
    private:
        String *data = nullptr;
        UInt64 count = 0LL;
        UInt64 collisionCount = 0LL;
    };
}
