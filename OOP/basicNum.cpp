#include <iostream>
using namespace std;

class basicNum{
    private:
        int* ptr;
    public:
        basicNum(int num){
            ptr = new int();
            *ptr = num;

            // ptr = new int(num); // is same as above
                                   // it allocates and initializes
                                   // the unnamed memory address on
                                   // the heap and sets its address 
                                   // to ptr
        }

        basicNum(const basicNum& obj){
            ptr = new int(*(obj.ptr));
        }

        void showNum(){
            cout << *ptr << endl;
        }

        int updateNum(int newNum){
            *ptr = newNum;
        }
        
    ~basicNum(){
        delete ptr;
    }
};


int main(){
    system("cls");
    basicNum num1(7);
    num1.showNum();

    basicNum num2(num1);
    num2.showNum();

    num2.updateNum(8);

    num1.showNum();
    num2.showNum();

    return 0;
}