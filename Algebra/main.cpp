//
//  main.cpp
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/10.
//

#include <iostream>
#include <memory>

using namespace std;

class Set{
public:
    virtual bool operator==(const Set&) const = 0;
    virtual bool operator!=(const Set&) const = 0;
    virtual Set &operator=(const Set&) = 0;
};

class AbelianGroup : public Set{
public:
    //加法演算の定義
    
    virtual AbelianGroup& operator+(const AbelianGroup&) = 0;
    //逆元の定義
    virtual const AbelianGroup& operator-() const = 0;
    //単位元を返す関数の定義
    virtual const AbelianGroup& identity() const = 0;
};

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



int main(){
    Integer a = 5;
    Integer b = 6;
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + a = " << a + a << endl;
    cout << "a + (-a)=" << a + (-a) << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a + (-b)=" << a + (-b) << endl;
    return 0;
}
