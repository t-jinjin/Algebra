//
//  Field.h
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/18.
//

#ifndef Field_h
#define Field_h
#include "Set.h"
#include "AbelianGroup.h"
#include "Group.h"

class Field : public AbelianGroup, public Group{
    virtual const Field& inv() const = 0;
};


#endif /* Field_h */
