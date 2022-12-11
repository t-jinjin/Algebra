//
//  AbelianSemiGroup.h
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/11.
//

#ifndef AbelianSemiGroup_h
#define AbelianSemiGroup_h

#include "Set.h"

class AbelianSemiGroup : public Set{
public:
    virtual AbelianSemiGroup& operator+(const AbelianSemiGroup&) = 0;
};

#endif /* AbelianSemiGroup_h */
