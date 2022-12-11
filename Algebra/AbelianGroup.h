//
//  AbelianGroup.h
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/11.
//

#ifndef AbelianGroup_h
#define AbelianGroup_h

#include "AbelianMonoid.h"

class AbelianGroup : public AbelianMonoid{
public:
    virtual const AbelianGroup& operator-() const = 0;
    virtual AbelianGroup& operator-(const AbelianGroup&) = 0;
    
};

#endif /* AbelianGroup_h */
