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
#include <fstream>
#include <cassert>

#include "Containers/HashTable.hpp"
#include "ErrorHandling/DuplicateValueException.hpp"
#include "ErrorHandling/RangeException.hpp"
#include "ErrorHandling/BufferOverrunException.hpp"
#include "ErrorHandling/BadAllocationException.hpp"

UInt16
AoAHW4ApplicationDelegate::applicationDidStart(const Container::Array<String> &arguments) const noexcept
{
    using Container::HashTable;
    using InputFileStream = std::ifstream;
    
    if (arguments.getLength() == 2) {
        UInt64 hashTableSize = std::stoll(arguments[1]);
        
        HashTable hashTable(hashTableSize);
//        InputFileStream inputFileStream("words.txt");
        
        try {
            hashTable.insert("blabla");
            
            try {
                hashTable.insert("blabla");
            } catch (DuplicateValueException &dve) {
                std::cout << "value already exists" << std::endl;
            }
                
            assert(hashTable.retrieve("blabla") == true);
                
            hashTable.remove("blabla");
                
            assert(hashTable.retrieve("blabla") == false);
                
            try {
                hashTable.remove("blabla");
            } catch (RangeException &re) {
                std::cout << "value does not exist" << std::endl;
            }
        } catch (BufferOverrunException &boe) {
            std::cout << "caught buffer overrun exception on address: " << &boe << std::endl;
        } catch (BadAllocationException &bae) {
            std::cout << "caught bad allocation exception on address: " << &bae << std::endl;
        } catch (...) {
            std::cout << "caught undefined exception" << std::endl;
        }
        
        return 0;
    } else {
        return 9;
    }
}
