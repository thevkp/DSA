#include "SLL.h"
#include <iostream>
using namespace std;



int main(){
    system("cls");

    SLL list;

    int input;
    cin >> input;

    while(input != -1){
        list.append(input);
        cin >> input;
    }

    list.printList();
    list.reverseList();
    list.printList();
    int n;
    cin >> n;
    cout << list.sumNLastNodes(n) << endl;



    return 0;
}

// $files = "main.cpp", "SLL.cpp"
// g++ $files -o main
// if ($?) {
//     .\main
// }