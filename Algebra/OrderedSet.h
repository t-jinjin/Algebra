//
//  OrderedSet.h
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/11.
//

#ifndef OrderedSet_h
#define OrderedSet_h

#include "Set.h"

class OrderedSet : public Set{
public:
    virtual bool operator<(const OrderedSet&) const = 0;
    virtual bool operator>(const OrderedSet&) const = 0;
    virtual bool operator<=(const OrderedSet&) const = 0;
    virtual bool operator>=(const OrderedSet&) const = 0;
};

#endif /* OrderedSet_h */
