//
//  AoAHW2ApplicationDelegate.hpp
//  AlgoHW2
//
//  Created by Buğra Ekuklu on 04.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#pragma once

#include "Bootstrapping/Application.hpp"

class AoAHW2ApplicationDelegate : public ApplicationDelegate {
public:
    UInt16 applicationDidStart(const Container::Array<String> &arguments) const noexcept override;
};
