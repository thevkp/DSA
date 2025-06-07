#include <iostream>
#include <typeinfo>
using namespace std;

int main(){
    int a = 50;
    int b = 78;
    const int* pt = &a; // const followed by pointer type prevents
                        // the pointer from changing the value
                        // pointer points to *pt cannot modify
                        // the value pointed by pt
                        // but pt can be assigned to a new value
                        // i.e. a new memory address
                        // 'a' itself is not a const
                        // 'a++' or a = 43 is valid

    // *pt = 80; invalid cause pt has type const 'int *'(PKi)
    pt = &b;
    a = a - 3;
    cout << typeid(pt).name() << endl;

    int* const ptr = &a; // const preceded by pointer type and
                         // and followed by pointer name prevents
                         // prevents pointer from pointing to
                         // new memory location i.e ptr cannot
                         // be reassigned and must be initialized
                         // during declaration
    // ptr = &b // invalid cause ptr is constant 
    *ptr = *ptr + 4;
    cout << typeid(ptr).name() << endl;

    int c = 49;

    int const* ptr1 = &c; // same as const int* pt
    ptr1 = &a;
    // *ptr1 = *ptr1++; // invalid cause ptrr1 has type const int*(PKi)
    cout << typeid(ptr1).name() << endl;



    return 0;
}