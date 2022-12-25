//
//  OrderedField.h
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/18.
//

#ifndef OrderedField_h
#define OrderedField_h
#include "Field.h"
#include "OrderedSet.h"

class OrderedField : public Field, public OrderedSet{
public:
    virtual const OrderedField& abs() const = 0;
};

#endif /* OrderedField_h */
