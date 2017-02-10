//
//  SpellCheckController.hpp
//  AoAHW4
//
//  Created by Buğra Ekuklu on 11.12.2016.
//  Copyright © 2016 Buğra Ekuklu. All rights reserved.
//

#pragma once

#include "../Models/SpellCheck.hpp"
#include "../Containers/HashTable.hpp"

class SpellCheckController {
public:
    SpellCheckController(Container::HashTable &wordsList);
    
    SpellCheck checkSpelling(const String &candidateWord);
    
private:
    Container::HashTable &wordsList;
    UInt64 spellChecksCount = 0;
};
