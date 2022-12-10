//
//  Integer.cpp
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/11.
//
#include <iostream>
#include "Set.h"
#include "AbelianGroup.h"

class Integer : public AbelianGroup{
public:
    Integer(int val){
        value_ = val;
    }
    ~Integer(){
        //delete this;
    }
    
    bool operator==(const Set& rhs) const override{
        const Integer rhs_cast = static_cast<const Integer&>(rhs);
        return value_ == rhs_cast.value_;
    }
    bool operator!=(const Set& rhs) const override{
        const Integer rhs_cast = static_cast<const Integer&>(rhs);
        return !(*this == rhs_cast);
    }
    Integer &operator=(const Set& rhs) override{
        const Integer& rhs_cast = static_cast<const Integer&>(rhs);
        value_ = rhs_cast.value_;
        return *this;
    }
    
    Integer& operator+(const AbelianGroup& rhs) override{
        const Integer& rhs_cast = static_cast<const Integer&>(rhs);
        int res = value_ + rhs_cast.value_;
        return *new Integer(res);
    }
    
    Integer& operator-() const override{
        return *new Integer(-value_);
    }
    
    Integer& identity() const override{
        return *new Integer(0);
    }
    
    int value(){
        return value_;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Integer& rhs){
        os << rhs.value_;
        return os;
    }
    
private:
    int value_;
};
