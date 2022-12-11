//
//  AbelianMonoid.h
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/11.
//

#ifndef AbelianMonoid_h
#define AbelianMonoid_h

#include "AbelianSemiGroup.h"

class AbelianMonoid : public AbelianSemiGroup{
public:
    virtual const AbelianMonoid& zero() const = 0;
};

#endif /* AbelianMonoid_h */
