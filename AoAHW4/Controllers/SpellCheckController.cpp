//
//  SpellCheckController.cpp
//  AoAHW4
//
//  Created by Buğra Ekuklu on 11.12.2016.
//  Copyright © 2016 Buğra Ekuklu. All rights reserved.
//

#include "SpellCheckController.hpp"

#include <algorithm>

using Container::Array;

SpellCheckController::SpellCheckController(const HashTable &wordsList)
: wordsList(wordsList)
{
    //  Blank implementation
}

SpellCheck
SpellCheckController::checkSpelling(const String &candidateWord)
{
    if (wordsList.retrieve(candidateWord)) {
        
        return SpellCheck(candidateWord, Array<String>(), SpellCheckResult::Success);
    } else {
        //  Copy the candidate word string
        auto copyOfCandidateWord = String(candidateWord);
        
        //  Transform it to lowercase
        std::transform(copyOfCandidateWord.begin(), copyOfCandidateWord.end(), copyOfCandidateWord.begin(), ::tolower);
        
        //  Take the underlying raw C string of it
        auto candidateCString = copyOfCandidateWord.data();
        
        //  Allocate a new raw C string to apply the modifications
        char *alteredCString = new char[candidateWord.size()]();
        
        //  Allocate the result array
        auto availableWords = Array<String>();
        
        for (UInt64 letterIndex = 0; letterIndex < candidateWord.size(); ++letterIndex) {
            for (signed char candidateLetter = 'a'; candidateLetter <= 'z'; ++candidateLetter) {
                //  Rollback modifications on the altered string
                std::memcpy(alteredCString, candidateCString, candidateWord.size());
                
                //  Do modifications
                alteredCString[letterIndex] = candidateLetter;
                
                //  If it exists, push it to the result array
                if (wordsList.retrieve(alteredCString)) {
                    availableWords.append(alteredCString);
                }
            }
        }
        
        return SpellCheck(candidateWord, availableWords, SpellCheckResult::Failure);
    }
}
