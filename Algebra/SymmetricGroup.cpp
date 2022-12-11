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
class SymmetricGroup : public Group {
public:
    SymmetricGroup(const std::array<int,n> elem){
        
        if (elem.size != n){
            //入力する要素の数が置換群の次数と異なる場合はエラーを返す．
        }
        //elemを並べ替えて
    }
    
    const int& operator()(int i) const {
        return element[i];
    }
    long get_size(){
        return element.size();
    }
    
private:
    std::array<int,n> element;
};
