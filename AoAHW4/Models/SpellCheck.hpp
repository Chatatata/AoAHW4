//
//  SpellCheck.hpp
//  AoAHW4
//
//  Created by Buğra Ekuklu on 11.12.2016.
//  Copyright © 2016 Buğra Ekuklu. All rights reserved.
//

#pragma once

#include "../Containers/Array.hpp"
#include "SpellCheckResult.hpp"

struct SpellCheck {
    convenience SpellCheck(String word, Container::Array<String> availableWords, SpellCheckResult result);
    
    const String word;
    const Container::Array<String> availableWords;
    const SpellCheckResult result;
};
