//
//  HashTableOperationController.hpp
//  AoAHW4
//
//  Created by Buğra Ekuklu on 12.12.2016.
//  Copyright © 2016 Buğra Ekuklu. All rights reserved.
//

#pragma once

#include "../Containers/HashTable.hpp"
#include "SpellCheckController.hpp"

class HashTableOperationController {
public:
    HashTableOperationController(Container::HashTable &hashTable);
    
    void run() noexcept;
    
private:
    Container::HashTable &hashTable;
    SpellCheckController scc;
    
    void onInsert(String key);
    void onRetreive(String key);
    void onDelete(String key);
};
