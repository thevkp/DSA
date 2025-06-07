#include "list.h"



int main(){
    
    SLL<int> list;



    int input;
    while(cin >> input && input != -1){
        list.append(input);
    }

    // list.print();
    for(auto x : list){
        cout << x << " ";
    }
    cout << endl;

    SLL<int>::Iterator it = list.begin();
    cout << *it << endl;
    // cout << it->data << endl;

    // cout << *it << endl << *(++it) << endl;
    // cout << boolalpha << (it == ++it) << endl;

    list.reverse();
    list.append(0);
    list.print();


    return 0;
}