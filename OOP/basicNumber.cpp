#include <iostream>
#include <cstdlib>
using namespace std;

class basicNumber{
    private:
        int n;
    public:
        basicNumber(int num){
            n = num;
        }

        void showNum(){
            cout << n << endl;
        }

        void updateNum(int newNum){
            n = newNum;
        }
};


int main(){
    system("cls");
    basicNumber num1(7);
    num1.showNum();

    basicNumber num2 = num1;
    num2.showNum();
   
    num1.updateNum(8);

    num1.showNum();
    num2.showNum();

    return 0;
}