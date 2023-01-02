//
//  RationalNumber.cpp
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/18.
//

#ifndef RationalNumber_h
#define RationalNumber_h

#include <iostream>
#include <stdio.h>
#include "Set.h"
#include "OrderedSet.h"
#include "OrderedField.h"
#include "Integer.h"

class RationalNumber : public OrderedField{
public:
    RationalNumber(int _p,int _q){
        if(_q == 0){
            throw std::runtime_error("Denominator is Zero.");
        }else{
            p = _p;
            q = _q;
        }
    }
    ~RationalNumber(){}
    
    bool operator==(const Set& rhs) const override{
        const RationalNumber& rhs_cast = dynamic_cast<const RationalNumber&>(rhs);
        return p * rhs_cast.q == q * rhs_cast.p;
    }
    bool operator!=(const Set& rhs) const override{
        const RationalNumber& rhs_cast = dynamic_cast<const RationalNumber&>(rhs);
        return !(*this == rhs_cast);
    }
    bool operator>=(const OrderedSet& rhs) const override{
        const RationalNumber& rhs_cast = dynamic_cast<const RationalNumber&>(rhs);
        return p * q * rhs_cast.q * rhs_cast.q >= p * q * q * rhs_cast.q;
    }
    bool operator<=(const OrderedSet& rhs) const override{
        const RationalNumber& rhs_cast = dynamic_cast<const RationalNumber&>(rhs);
        return p * q * rhs_cast.q * rhs_cast.q <= p * q * q * rhs_cast.q;
    }
    bool operator>(const OrderedSet& rhs) const override{
        const RationalNumber& rhs_cast = dynamic_cast<const RationalNumber&>(rhs);
        return p * q * rhs_cast.q * rhs_cast.q > p * q * q * rhs_cast.q;
    }
    bool operator<(const OrderedSet& rhs) const override{
        const RationalNumber& rhs_cast = dynamic_cast<const RationalNumber&>(rhs);
        return p * q * rhs_cast.q * rhs_cast.q < p * q * q * rhs_cast.q;
    }
    RationalNumber &operator=(const Set& rhs) override{
        const RationalNumber& rhs_cast = dynamic_cast<const RationalNumber&>(rhs);
        p = rhs_cast.p;
        q = rhs_cast.q;
        return *this;
    }
    RationalNumber& operator+(const AbelianSemiGroup& rhs) override{
        const RationalNumber& rhs_cast = dynamic_cast<const RationalNumber&>(rhs);
        return *new RationalNumber(p * rhs_cast.q + rhs_cast.p * q, q * rhs_cast.q);
    }
    RationalNumber& operator-() const override{
        return *new RationalNumber(-p, q);
    }
    RationalNumber& operator-(const AbelianGroup& rhs) override{
        const RationalNumber& rhs_cast = dynamic_cast<const RationalNumber&>(rhs);
        return *this + (-rhs_cast);
    }
    RationalNumber& operator*(const SemiGroup& rhs) override{
        const RationalNumber& rhs_cast = dynamic_cast<const RationalNumber&>(rhs);
        return *new RationalNumber(p * rhs_cast.p, q * rhs_cast.q);
    }
    RationalNumber& zero() const override{
        return *new RationalNumber(0,1);
    }
    RationalNumber& one() const override{
        return *new RationalNumber(1,1);
    }
    RationalNumber& inv() const override{
        return *new RationalNumber(q,p);
    }
    RationalNumber& abs() const override{
        int _p,_q;
        if (p < 0) _p = -p;
        if (q < 0) _q = -q;
        return *new RationalNumber(_p,_q);
    }
    
    RationalNumber& operator/(const Group& rhs) override{
        const RationalNumber& rhs_cast = dynamic_cast<const RationalNumber&>(rhs);
        return *this * rhs_cast.inv();
    }
    
    friend std::ostream& operator<<(std::ostream& os, const RationalNumber& rhs){
        os << rhs.p;
        os << " / ";
        os << rhs.q;
        return os;
    }
    
private:
    int p;
    int q;
};

#endif
