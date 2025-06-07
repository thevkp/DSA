#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;


int main(){
    system("cls");

    unordered_set<int> s;

    int input;
    cin >> input;

    while(input != -1){
        s.insert(input);
        cin >> input;
    }

    for(int num : s){
        cout << num << " ";
    }
    cout << endl;

    cout << boolalpha;
    cout << s.count(4) << endl;




    return 0;
}