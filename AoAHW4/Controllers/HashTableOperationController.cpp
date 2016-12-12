//
//  HashTableOperationController.cpp
//  AoAHW4
//
//  Created by Buğra Ekuklu on 12.12.2016.
//  Copyright © 2016 Buğra Ekuklu. All rights reserved.
//

#include "HashTableOperationController.hpp"

#include <iostream>
#include <fstream>

#include "../ErrorHandling/DuplicateValueException.hpp"
#include "../ErrorHandling/BadAllocationException.hpp"
#include "../ErrorHandling/RangeException.hpp"

HashTableOperationController::HashTableOperationController(Container::HashTable &hashTable)
: hashTable(hashTable), scc(hashTable)
{
    //  Blank implementation
}

void
HashTableOperationController::run() noexcept
{
    using InputFileStream = std::ifstream;
    using OutputFileStream = std::ofstream;
    
    InputFileStream inputFileStream("words.txt");
    OutputFileStream outputFileStream("150120016_output.txt");
    String bufferString;
    
    try {
        while (std::getline(inputFileStream, bufferString)) {
            if (bufferString.back() == '\r') {
                bufferString.pop_back();
            }
            
            if (bufferString.substr(0, 6) == "insert") {
                onInsert(bufferString.substr(7, bufferString.size()));
            } else if (bufferString.substr(0, 6) == "delete") {
                onDelete(bufferString.substr(7, bufferString.size()));
            } else if (bufferString.substr(0, 8) == "retrieve") {
                onRetreive(bufferString.substr(9, bufferString.size()));
            } else if (bufferString == "\n" || bufferString == "") {
                std::cout << "Got whitespace, continuing..." << std::endl;
            } else {
                std::cout << "Unexpected statement: \"" << bufferString << "\"" << std::endl;
            }
                
            std::cout << "-------------------------------------" << std::endl;
        }
                
        std::cout << "-------------------------------------" << std::endl;
                
        std::cout << "TOTAL COLLISIONS: " << hashTable.getTotalCollisionCount() << std::endl;
    } catch (RangeException &boe) {
        std::cout << "Caught buffer overrun exception at address: " << &boe << std::endl;
    }
                
    for (UInt64 i = 0; i < hashTable.size; ++i) {
        outputFileStream << i << ": " << hashTable.data[i] << std::endl;
    }
}

void
HashTableOperationController::onInsert(String key)
{
    std::cout
    << "h(x) result is "
    << hashTable.hashValue(key)
    << " for: "
    << key
    << std::endl;
    
    try {
        auto cellNumber = hashTable.insert(key);
        
        std::cout
        << "INSERT: The word '"
        << key
        << "' is put in the cell number "
        << cellNumber
        << std::endl;
    } catch (DuplicateValueException &dve) {
        std::cout
        << "The word '"
        << key
        << "' is already in the dictionary!"
        << std::endl;
    } catch (BadAllocationException &bae) {
        std::cout
        << "WARNING: There is no empty space in the hash table for the word: "
        << key
        << std::endl;
    }
    
    std::cout
    << "COLLISIONS: "
    << hashTable.getLastCollisionCount()
    << std::endl;
}

void
HashTableOperationController::onRetreive(String key)
{
    try {
        auto index = hashTable.findIndex(key);
        
        std::cout
        << "RETRIEVE: The word '"
        << key
        << "' found in the dictionary with index "
        << index
        << std::endl;
        
        std::cout
        << "COLLISIONS: "
        << hashTable.getLastCollisionCount()
        << std::endl;
    } catch (RangeException &re) {
        std::cout
        << "The word '"
        << key
        << "' couldn't be found in the dictionary."
        << std::endl
        << "Looking for possible suggestions."
        << std::endl
        << "SUGGESTIONs for "
        << key
        << ": ";
        
        auto spellCheckResult = scc.checkSpelling(key);
        
        for (UInt64 i = 0; i < spellCheckResult.availableWords.getLength(); ++i) {
            std::cout << spellCheckResult.availableWords[i] << ", ";
        }
        
        std::cout << std::endl;
        
        std::cout
        << "COLLISIONS: "
        << spellCheckResult.numberOfCollisions
        << std::endl;
    }
}

void
HashTableOperationController::onDelete(String key)
{
    try {
        hashTable.remove(key);
        
        std::cout
        << "REMOVE: The word '"
        << key
        << "' is removed from the dictionary."
        << std::endl;
    } catch (RangeException &re) {
        std::cout
        << "WARNING: The word '"
        << key
        << "' couldn't be found in the dictionary."
        << std::endl;
    }
    
    std::cout
    << "COLLISIONS: "
    << hashTable.getLastCollisionCount()
    << std::endl;
}