# AoAHW2
Analysis of Algorithms, Assignment 2.

Implemented in non-purist but yet cool way.

Pull requests will be gladly accepted, if you have suggestions.

## Build

`g++ AoAHW2ApplicationDelegate.cpp IO/Parser.cpp Bootstrapping/Application.cpp Models/Line.cpp Models/SemanticWord.cpp Strategies/DeterministicQuickSortStrategy.cpp Strategies/LineCountedQuickSortStrategy.cpp Strategies/RandomizedQuickSortStrategy.cpp Supporting\ Files/main.cpp -std=c++11 -Wall -O3 -o main`


## Run

`./main 1 100 500` for the first algorithm with 100 and 500 values for M and N, respectively.

`./main 2 500000` for the second algorithm to sort first 500000, K values in the text file.

Tested on Clang (Apple LLVM 8.0.0, clang-800.0.42.1) and GCC (4.8.5).
