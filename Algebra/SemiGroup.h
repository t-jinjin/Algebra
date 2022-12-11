//
//  SemiGroup.h
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/11.
//

#ifndef SemiGroup_h
#define SemiGroup_h
#include "Set.h"

class SemiGroup : public Set{
public:
    virtual SemiGroup& operator*(const SemiGroup&) = 0;
};

#endif /* SemiGroup_h */
