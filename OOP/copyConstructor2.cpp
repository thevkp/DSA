#include <iostream>
using namespace std;


class Example{
    private:
        int data;
    public:
        // default constructor
        Example() {
            data = 0;
        }

        // copy constructor
        Example(const Example& obj){
            data = obj.data;
        }

        void showData(){
            cout << data << endl;
        }

        void updateData(int data){
            this->data = data;
        }
};


int main(){
    Example eg; // instantiating Example with default constructor
    Example eg2(eg);

    eg.showData();
    eg2.showData();

    eg.updateData(1);

    eg.showData();
    eg2.showData();

    return 0;
}