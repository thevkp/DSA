#include <iostream>
using namespace std;

class constructorType{
    private:
        int num;
    public:
        // constructor with no paramters
        constructorType(){
            num = 0;
        }

        // constructor to initialize the num with user input
        constructorType(int initializeNum){
            num = initializeNum;
        }

        int getNum(){
            return num;
        }
};

int main(){
    constructorType construct1; // construct takes no arguments, thus will call constructor with no paramters
    cout << construct1.getNum() << endl;

    constructorType construct2(3); // will use second constructor
    cout << construct2.getNum() << endl;


    return 0;
}