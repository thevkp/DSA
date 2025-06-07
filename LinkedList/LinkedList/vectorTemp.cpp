#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr;
    int input;
    cin >> input;
    while(input != -1){
        arr.push_back(input);
        cin >> input;
    }

    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}