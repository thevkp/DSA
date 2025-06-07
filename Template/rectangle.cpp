#include <iostream>
using namespace std;

template<typename T>


class Rectangle{
    private:
        T len, wid;
    public:
        Rectangle(T len, T wid){
            this->len = len;
            this->wid = wid;
        }

        T getArea(){
            return len * wid;
        }
};


int main(){
    system("cls");

    Rectangle<int> rect(2, 6);

    cout << rect.getArea() << endl;



    return 0;
}