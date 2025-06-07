#include <iostream>
using namespace std;

class Example{
    int* ptr;
    public:
        Example(int value){
            ptr = new int(value);
        }

        // copy constructor;
        Example(const Example& obj){
            ptr = new int(*obj.ptr);
        }

        void show(){
            cout << *ptr << endl;
        }

        ~Example(){
            delete ptr;
        }
};


int main(){
    Example obj1(2);

    obj1.show();

    Example obj2 = obj1;
    obj2.show();

    return 0;
}