//
//  Monoid.h
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/11.
//

#ifndef Monoid_h
#define Monoid_h
#include "SemiGroup.h"

class Monoid : virtual public SemiGroup{
public:
    virtual const Monoid& one() const = 0;
};

#endif /* Monoid_h */
