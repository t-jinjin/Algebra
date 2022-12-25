//
//  IntegerAbelianGroupAbelianGroup.cpp
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/11.
//
#include <iostream>
#include "Set.h"
#include "AbelianGroup.h"

class IntegerAbelianGroup : public AbelianGroup{
public:
    IntegerAbelianGroup(int val){
        value_ = val;
    }
    ~IntegerAbelianGroup(){
        //delete this;
    }
    
    bool operator==(const Set& rhs) const override{
        const IntegerAbelianGroup& rhs_cast = dynamic_cast<const IntegerAbelianGroup&>(rhs);
        return value_ == rhs_cast.value_;
    }
    bool operator!=(const Set& rhs) const override{
        const IntegerAbelianGroup& rhs_cast = dynamic_cast<const IntegerAbelianGroup&>(rhs);
        return !(*this == rhs_cast);
    }
    IntegerAbelianGroup &operator=(const Set& rhs) override{
        const IntegerAbelianGroup& rhs_cast = dynamic_cast<const IntegerAbelianGroup&>(rhs);
        value_ = rhs_cast.value_;
        return *this;
    }
    
    IntegerAbelianGroup& operator+(const AbelianSemiGroup& rhs) override{
        const IntegerAbelianGroup& rhs_cast = dynamic_cast<const IntegerAbelianGroup&>(rhs);
        int res = value_ + rhs_cast.value_;
        return *new IntegerAbelianGroup(res);
    }
    
    IntegerAbelianGroup& operator-() const override{
        return *new IntegerAbelianGroup(-value_);
    }
    
    IntegerAbelianGroup& operator-(const AbelianGroup& rhs) override{
        const IntegerAbelianGroup& rhs_cast = static_cast<const IntegerAbelianGroup&>(rhs);
        return *this + (-rhs_cast);
        //int res = value_ - rhs_cast.value_;
        //return *new IntegerAbelianGroup(res);
    }
    
    IntegerAbelianGroup& zero() const override{
        return *new IntegerAbelianGroup(0);
    }
    
    int value(){
        return value_;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const IntegerAbelianGroup& rhs){
        os << rhs.value_;
        return os;
    }
    
private:
    int value_;
};
