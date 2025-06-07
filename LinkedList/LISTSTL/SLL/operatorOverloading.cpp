#include <iostream>
using namespace std;

class Number{
    private:
        int n;
    public:
        Number(int set_n) : n(set_n) {}

        int getN() {
            return n;
        }

        Number operator+(const Number& other){
            return Number(this->n + other.n);
        }

        // int operator+(const Number& other){
        //     return this->n + other.n;
        // }

        bool operator==(const Number& other){
            return (this->n == other.n);
        }

        bool operator!=(const Number& other){
            return (this->n != other.n);
        }
};


int main(){
    system("cls");

    Number num1(3);
    Number num2(4);

    Number res = num1 + num2;

    cout << res.getN() << endl;
    // cout << num1 + num2 << endl;
    cout << (num1 == num2) << endl;

    bool notEqual = num1 != num2;
    cout << notEqual << endl;
    


    return 0;
}