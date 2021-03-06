//
//  SpellCheck.cpp
//  AoAHW4
//
//  Created by Buğra Ekuklu on 11.12.2016.
//  Copyright © 2016 Buğra Ekuklu. All rights reserved.
//

#include "SpellCheck.hpp"

#include "../Containers/Array.cpp"

SpellCheck::SpellCheck(String word,
                       Container::Array<String> availableWords,
                       SpellCheckResult result,
                       UInt64 numberOfCollisions)
: word(word), availableWords(availableWords), result(result), numberOfCollisions(numberOfCollisions)
{
    //  Blank implementation
}

