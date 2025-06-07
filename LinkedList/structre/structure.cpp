#include <iostream>
using namespace std;

struct inflatable{
    int items;
    float size;
    double price;
};

int main(){
    inflatable ballon;
    ballon.items = 2;
    ballon.size = 4.3;
    ballon.price = 5;

    cout << ballon.items << "\n";
    cout << ballon.size  << "\n";
    cout << ballon.price << "\n";

    return 0;
}