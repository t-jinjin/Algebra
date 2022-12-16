//
//  OrderedRing.h
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/17.
//

#ifndef OrderedRing_h
#define OrderedRing_h

#include "Ring.h"
#include "OrderedSet.h"

class OrderedRing : public Ring, OrderedSet{
public:
    virtual const OrderedRing& abs() const = 0;
};

#endif /* OrderedRing_h */
