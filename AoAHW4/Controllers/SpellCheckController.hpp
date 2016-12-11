//
//  SpellCheckController.hpp
//  AoAHW4
//
//  Created by Buğra Ekuklu on 11.12.2016.
//  Copyright © 2016 Buğra Ekuklu. All rights reserved.
//

#pragma once

#include "../Models/SpellCheck.hpp"
#include "../Containers/HashTable.cpp"

class SpellCheckController {
public:
    SpellCheckController(const HashTable &wordsList);
    
    SpellCheck checkSpelling(const String &candidateWord);
    
private:
    HashTable wordsList;
    UInt64 spellChecksCount = 0;
};
