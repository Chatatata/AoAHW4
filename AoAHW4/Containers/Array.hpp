//
//  Array.hpp
//  AlgoHW2
//
//  Created by Buğra Ekuklu on 31.10.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//


#pragma once

#include "../PrefixHeader.pch"

namespace Container {
    
    template <typename T>
    class Array {
    public:
        static const UInt64 initialLength = 1000005LL;
        
        Array();
        Array(const Array &other);
        Array &operator = (const Array &other);
        
        T &objectAtIndex(const UInt64 index) const;
        T &operator [] (const UInt64 index) const;
        void append(const T &object) noexcept;
        UInt64 getLength() const noexcept;
        void setLength(const UInt64 length) noexcept;
        
    private:
        T *data = nullptr;
        UInt64 length = 0LL;
    };

}

