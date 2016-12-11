//
//  BadAllocationException.hpp
//  AoAHW4
//
//  Created by Buğra Ekuklu on 11.12.2016.
//  Copyright © 2016 Buğra Ekuklu. All rights reserved.
//

#pragma once

#include "../PrefixHeader.pch"

class BadAllocationException {
public:
    BadAllocationException(const UInt64 preferredSize);
    
    const UInt64 preferredSize = 0LL;
};
