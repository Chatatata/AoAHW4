//
//  Application.cpp
//  AlgoHW2
//
//  Created by Buğra Ekuklu on 04.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#include "Application.hpp"

Application::Application(const ApplicationDelegate &delegate,
                            int argc,
                            const char * argv[])
{
    using Container::Array;
    
    Array<String> argumentVector;
    
    for (Size i = 0; i < static_cast<Size>(argc); ++i) {
        argumentVector.push_back(argv[i]);
    }
    
    returnValue = delegate.applicationDidStart(argumentVector);
}

Application::operator int() const noexcept
{
    return returnValue;
}
