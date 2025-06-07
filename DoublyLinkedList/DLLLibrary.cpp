#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> myList;
    myList.push_back(1);
    myList.push_back(2);

    for(int num : myList){
        cout << num << " ";
    }

    return 0;
}