//
//  AoAHW4ApplicationDelegate.cpp
//  AoAHW4
//
//  Created by Buğra Ekuklu on 04.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#include "AoAHW4ApplicationDelegate.hpp"

#include <iostream>
#include <string>

#include "Controllers/HashTableOperationController.hpp"

UInt16
AoAHW4ApplicationDelegate::applicationDidStart(const Container::Array<String> &arguments) const noexcept
{
    using Container::HashTable;
    
    if (arguments.getLength() == 2) {
        UInt64 hashTableSize = std::stoll(arguments[1]);
        
        HashTable hashTable(hashTableSize);
        HashTableOperationController htoc(hashTable);
        
        htoc.run();
                    
        return 0;
    } else {
        
        return 1;
    }
}
