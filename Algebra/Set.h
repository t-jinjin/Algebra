//
//  Set.h
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/11.
//

#ifndef Set_h
#define Set_h

class Set{
public:
    virtual bool operator==(const Set&) const = 0;
    virtual bool operator!=(const Set&) const = 0;
    virtual Set &operator=(const Set&) = 0;
};

#endif /* Set_h */
