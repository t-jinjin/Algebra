//
//  AbelianGroup.h
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/11.
//

#ifndef AbelianGroup_h
#define AbelianGroup_h

#include "Set.h"
#include <memory>

class AbelianGroup : public Set{
public:
    //加法演算の定義
    virtual AbelianGroup& operator+(const AbelianGroup&) = 0;
    //逆元の定義
    virtual const AbelianGroup& operator-() const = 0;
    //単位元を返す関数の定義
    virtual const AbelianGroup& identity() const = 0;
};

#endif /* AbelianGroup_h */
