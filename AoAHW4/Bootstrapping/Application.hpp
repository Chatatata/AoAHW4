//
//  Application.hpp
//  AlgoHW2
//
//  Created by Buğra Ekuklu on 04.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#pragma once

#include "../Containers/Array.hpp"

#include <type_traits>

class ApplicationDelegate {
public:
    virtual UInt16 applicationDidStart(const Container::Array<String> &arguments) const noexcept = 0;
};

class Application {
public:
    Application(const ApplicationDelegate &delegate, int argc, const char * argv[]);
    
    operator int() const noexcept;
    
    UInt16 returnValue = 0;
};


