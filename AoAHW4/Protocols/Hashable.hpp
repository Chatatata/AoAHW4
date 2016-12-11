//
//  Hashable.hpp
//  AoAHW4
//
//  Created by Buğra Ekuklu on 11.12.2016.
//  Copyright © 2016 Buğra Ekuklu. All rights reserved.
//

#pragma once

#include "../PrefixHeader.pch"

protocol Hashable {
    virtual UInt64 hashValue() const noexcept = 0;
};
