//
//  Integer.cpp
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/11.
//
#include <iostream>
#include "Set.h"
#include "OrderedSet.h"
#include "OrderedRing.h"

class Integer : public OrderedRing{
public:
    Integer(int val){
        value_ = val;
    }
    ~Integer(){
        //delete this;
    }
    
    bool operator==(const Set& rhs) const override{
        const Integer& rhs_cast = static_cast<const Integer&>(rhs);
        return value_ == rhs_cast.value_;
    }
    bool operator!=(const Set& rhs) const override{
        const Integer& rhs_cast = static_cast<const Integer&>(rhs);
        return !(*this == rhs_cast);
    }
    
    bool operator>=(const OrderedSet& rhs) const override{
        const Integer& rhs_cast = static_cast<const Integer&>(rhs);
        return value_ >= rhs_cast.value_;
    }
    
    bool operator<=(const OrderedSet& rhs) const override{
        const Integer& rhs_cast = static_cast<const Integer&>(rhs);
        return value_ <= rhs_cast.value_;
    }
    
    bool operator>(const OrderedSet& rhs) const override{
        const Integer& rhs_cast = static_cast<const Integer&>(rhs);
        return value_ > rhs_cast.value_;
    }
    
    bool operator<(const OrderedSet& rhs) const override{
        const Integer& rhs_cast = static_cast<const Integer&>(rhs);
        return value_ < rhs_cast.value_;
    }
    
    Integer &operator=(const Set& rhs) override{
        const Integer& rhs_cast = static_cast<const Integer&>(rhs);
        value_ = rhs_cast.value_;
        return *this;
    }
    
    Integer& operator+(const AbelianSemiGroup& rhs) override{
        const Integer& rhs_cast = static_cast<const Integer&>(rhs);
        return *new Integer(value_ + rhs_cast.value_);
    }
    
    Integer& operator-() const override{
        return *new Integer(-value_);
    }
    
    Integer& operator-(const AbelianGroup& rhs) override{
        const Integer& rhs_cast = static_cast<const Integer&>(rhs);
        return *this + (-rhs_cast);
    }
    
    Integer& operator*(const SemiGroup& rhs) override{
        const Integer& rhs_cast = static_cast<const Integer&>(rhs);
        return *new Integer(value_ * rhs_cast.value_);
    }
    
    Integer& zero() const override{
        return *new Integer(0);
    }
    
    Integer& one() const override{
        return *new Integer(1);
    }
    
    Integer& abs() const override{
        if (*this >= zero()){
            return *this;
        }else{
            return -(*this);
        }
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
