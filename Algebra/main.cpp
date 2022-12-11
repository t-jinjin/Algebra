//
//  main.cpp
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/10.
//

#include <iostream>
#include "Integer.cpp"
using namespace std;

bool is_identity(Integer a){
    Integer e = a.zero();
    return e == a + e && e == e + a;
}


int main(){
    Integer a = 5;
    Integer b = 6;
    cout << is_identity(a) << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + a = " << a + a << endl;
    cout << "a + (-a)=" << a + (-a) << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a + (-b)=" << a + (-b) << endl;
    return 0;
}
