//
//  main.cpp
//  Algebra
//
//  Created by Takuma Jinnai on 2022/12/10.
//

#include <iostream>
#include "IntegerAbelianGroup.cpp"
#include "SymmetricGroup.cpp"
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

void test_SymmetricGroup(){
    try{
        SymmetricGroup<4> a({1,3,0,2});
        SymmetricGroup<4> b({0,3,1,2});
        cout << "a = " << a << endl;
        cout << "a^-1 = " << a.inv() << endl;
        cout << "a * a^-1 " << a * a.inv() << endl;
        cout << "b = " << b << endl;
        cout << "b^-1 = " << b.inv() << endl;
        cout << "b^-1 * b " << b * b.inv() << endl;
        
        
    }catch(std::runtime_error err){
        std::cerr << err.what() << std::endl;
    }
}


int main(){
    //test_IntegerAbelianGroup();
    test_SymmetricGroup();
    return 0;
}
