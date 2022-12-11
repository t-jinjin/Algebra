//
//  main.cpp
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/10.
//

#include <iostream>
#include "IntegerAbelianGroup.cpp"
//#include "IntegerAbelianGroup.cpp"
using namespace std;

void test_IntegerAbelianGroup(){
    IntegerAbelianGroup a = 5;
    IntegerAbelianGroup b = 6;
    //cout << is_identity(a) << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + a = " << a + a << endl;
    cout << "a + (-a)=" << a + (-a) << endl;
    cout << "a - a = " << a - a << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a + (-b)=" << a + (-b) << endl;
    cout << "a - b=" << a - b << endl;
}



int main(){
    test_IntegerAbelianGroup();
    return 0;
}
