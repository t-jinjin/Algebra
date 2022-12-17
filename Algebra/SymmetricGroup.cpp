//
//  SymmetricGroup.cpp
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/11.
//

#include <iostream>
#include <algorithm>
#include <array>
#include "Group.h"

template <int n>
class SymmetricGroup : public Group {
public:
    //
    SymmetricGroup(const std::array<int,n> elem){
        if (elem.size() != n){
            //入力する要素の数が置換群の次数と異なる場合はエラーを返す．
            throw std::runtime_error("Size Invalid.");
        }else{
            //入力する要素が0~n-1の並べ替えになっているかどうかチェックし，そうなっていなければエラーを返す．
            std::array<int, n> elem_sort = elem;
            std::sort(elem_sort.begin(),elem_sort.end());
            
            bool flag = true;
            for (int i = 0; i < n; i++){
                if (i != elem_sort[i]){
                    flag = false;
                    break;
                }
            }
            if (flag == false){
                throw std::runtime_error("Element Invalid.");
            }
        }
        element = elem;
    }
    ~SymmetricGroup(){}
    
    bool operator==(const Set& rhs) const override{
        const SymmetricGroup rhs_cast = dynamic_cast<const SymmetricGroup&>(rhs);
        bool flag = true;
        for (int i=0;i<n;i++){
            if (element[i] != rhs_cast.element[i]){
                flag = false;
                break;
            }
        }
        return flag;
    }
    bool operator!=(const Set& rhs) const override{
        const SymmetricGroup& rhs_cast = dynamic_cast<const SymmetricGroup&>(rhs);
        return !(*this == rhs_cast);
    }
    
    SymmetricGroup &operator=(const Set& rhs) override{
        const SymmetricGroup& rhs_cast = dynamic_cast<const SymmetricGroup&>(rhs);
        for (int i=0;i<n;i++){
            element[i] = rhs_cast.element[i];
        }
        return *this;
    }
    
    SymmetricGroup& operator*(const SemiGroup& rhs) override{
        const SymmetricGroup& rhs_cast = dynamic_cast<const SymmetricGroup&>(rhs);
        std::array<int,n> result;
        for (int i=0; i < n; i++){
            result[i] = element[rhs_cast.element[i]];
        }
        return *new SymmetricGroup(result);
    }
    
    SymmetricGroup& one() const override{
        std::array<int,n> one;
        for (int i=0; i < n; i++){
            one[i] = i;
        }
        return *new SymmetricGroup(one);
    }
    
    SymmetricGroup& inv() const override{
        std::array<int,n> inv;
        for (int i=0; i < n; i++){
            inv[element[i]] = i;
        }
        return *new SymmetricGroup(inv);
    }
    
    SymmetricGroup& operator/(const Group& rhs) override{
        const SymmetricGroup& rhs_cast = static_cast<const SymmetricGroup&>(rhs);
        return *this * rhs_cast.inv();
    }
    
    friend std::ostream& operator<<(std::ostream& os, const SymmetricGroup& rhs){
        os << std::endl;
        os << "[\t";
        for (int i = 0; i < n; i++){
            os << i << "\t";
        }
        os << "]";
        os << std::endl;
        os << "[\t";
        for (int i = 0; i < n; i++){
            os << rhs.element[i] << "\t";
        }
        os << "]";
        return os;
    }
    
private:
    std::array<int,n> element;
};
