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
        
        const UInt64 size = 0;
        
        UInt64 hashValue(String key);
        void insert(String key) noexcept;
        Boolean retrieve(String key) noexcept;
        Boolean remove(String key) noexcept;
    
    private:
        String *data = nullptr;
        UInt64 count = 0;
        UInt64 collisionCount = 0;
    };
}
