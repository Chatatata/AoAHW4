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
#include <sstream>

#include "Controllers/SpellCheckController.hpp"
#include "ErrorHandling/DuplicateValueException.hpp"
#include "ErrorHandling/RangeException.hpp"
#include "ErrorHandling/BufferOverrunException.hpp"
#include "ErrorHandling/BadAllocationException.hpp"

UInt16
AoAHW4ApplicationDelegate::applicationDidStart(const Container::Array<String> &arguments) const noexcept
{
    using Container::HashTable;
    using InputFileStream = std::ifstream;
    using OutputFileStream = std::ofstream;
    
    if (arguments.getLength() == 2) {
        UInt64 hashTableSize = std::stoll(arguments[1]);
        
        HashTable hashTable(hashTableSize);
        SpellCheckController scc(hashTable);
        InputFileStream inputFileStream("words.txt");
        OutputFileStream outputFileStream("150120016_output.txt");
        std::string bufferString;
        
        try {
            while (std::getline(inputFileStream, bufferString)) {
                
                if (bufferString.back() == '\r') {
                    bufferString.pop_back();
                }
                
                if (bufferString.substr(0, 6) == "insert") {
                    auto string = bufferString.substr(7, bufferString.size());
                    
                    std::cout
                    << "h(x) result is "
                    << hashTable.hashValue(string)
                    << " for: "
                    << string
                    << std::endl;
                    
                    try {
                        auto cellNumber = hashTable.insert(string);
                        
                        std::cout
                        << "INSERT: The word '"
                        << string
                        << "' is put in the cell number "
                        << cellNumber
                        << std::endl;
                    } catch (DuplicateValueException &dve) {
                        std::cout
                        << "The word '"
                        << string
                        << "' is already in the dictionary!"
                        << std::endl;
                    } catch (BadAllocationException &bae) {
                        std::cout
                        << "WARNING: There is no empty space in the hash table for the word: "
                        << string
                        << std::endl;
                    }
                    
                    std::cout
                    << "COLLISIONS: "
                    << hashTable.getLastCollisionCount()
                    << std::endl;
                } else if (bufferString.substr(0, 6) == "delete") {
                    auto string = bufferString.substr(7, bufferString.size());
                            
                    try {
                        hashTable.remove(string);
                                
                        std::cout
                        << "REMOVE: The word '"
                        << string
                        << "' is removed from the dictionary."
                        << std::endl;
                    } catch (RangeException &re) {
                        std::cout
                        << "WARNING: The word '"
                        << string
                        << "' couldn't be found in the dictionary."
                        << std::endl;
                    }
                    
                    std::cout
                    << "COLLISIONS: "
                    << hashTable.getLastCollisionCount()
                    << std::endl;
                } else if (bufferString.substr(0, 8) == "retrieve") {
                    auto string = bufferString.substr(9, bufferString.size());
                    
                    try {
                        auto index = hashTable.findIndex(string);
                        
                        std::cout
                        << "RETRIEVE: The word '"
                        << string
                        << "' found in the dictionary with index "
                        << index
                        << std::endl;
                    } catch (RangeException &re) {
                        std::cout
                        << "The word '"
                        << string
                        << "' couldn't be found in the dictionary."
                        << std::endl
                        << "Looking for possible suggestions."
                        << std::endl
                        << "SUGGESTIONs for "
                        << string
                        << ": ";
                        
                        auto spellCheckResult = scc.checkSpelling(string);
                        
                        for (UInt64 i = 0; i < spellCheckResult.availableWords.getLength(); ++i) {
                            std::cout << spellCheckResult.availableWords[i] << ", ";
                        }
                        
                        std::cout << std::endl;
                    }
                            
                    std::cout
                    << "COLLISIONS: "
                    << hashTable.getLastCollisionCount()
                    << std::endl;
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
                    
        return 0;
    } else {
        
        return 1;
    }
}
