//
//  Group.h
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/11.
//

#ifndef Group_h
#define Group_h

#include "Monoid.h"

class Group : public Monoid{
public:
    virtual const inv() const = 0;
    virtual operator/(const Group&) = 0;
};

#endif /* Group_h */
