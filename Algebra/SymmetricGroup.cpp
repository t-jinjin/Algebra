//
//  SymmetricGroup.cpp
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/11.
//

#include <iostream>
#include <array>
#include "Group.h"

template <int n>
class SymmetricGroup : public Group{
public:
    SymmetricGroup(){};
    ~SymmetricGroup(){};
    
    bool operator==(const Set& rhs) const override{
        const SymmetricGroup rhs_cast = static_cast<const 
    }
    
private:
    std::array<int, n> val;
};
