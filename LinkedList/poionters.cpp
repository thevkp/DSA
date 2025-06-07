#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    system("cls");
    int* fellow; // points to 0x401a7b, (output after running)

    // *fellow = 123; // fellow has a type int*
                      // 123 has a type int
    // fellow = 0x401a7b; // type mismatch, this is a valid memory address but it will treated as an int because addresses are integers(but not 'int')
                        // also there is nothing in the program to tell the computer that this is an address

    // 0x401a7b has type 'int', typecasting it to 'int *' and then assigning to fellow is valid
    fellow = (int *)0x401a7b; // types now matches, but fellow is still not pointing to any valid memory address
                              // however when declared 'fellow' points to 0x401a7b, here 0x401a7b(4201083) is just
                              // a normal integer(hexadeciml) like 1, 2, 10, -13, 0xa4b, 010000100001

    // We can typecast 'int' to 'int *' but it will not be a memory address
    int* pt;
    pt = (int *)14;
    cout << pt << endl; // 14 in hexadecimal is 0xe, but has type 'int *' and it does not make it a valid memory address
    cout << (int *)4201083 << endl; // 4201083 in hexadecimal is 0x401a7b 

    // *fellow = 123; // dereferencing 'fellow' here is not valid, as 0x401a7b(4201083) is interpreted
                      // as an integer, in fact it is an integer but typecasted to 'int *' 
                      // cout << *fellow << endl; thus, is invalid
    // cout << (int *)4201083 << endl; // yields 0x401a7b

    // *((int *)0x401a7b) = 123; // this also invalid, it's like *((int *)4201083) 

    int data = 1123;
    fellow = &data;

    cout << fellow << endl;
    cout << *fellow << endl;
    
    // cout << 0x401a7b << endl;
    // cout << 0x61ff04 << endl;
    // cout << (int *)6422276 << endl;
    return 0;
}