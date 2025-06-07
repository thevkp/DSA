#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isPresent(vector<int>& arr, int key){
    vector<int>::iterator it;
    
    for(it = arr.begin(); it != arr.end(); it++){
        if(*it == key)
            return true;
    }

    return false;
}

void printVector(vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] <<  " ";
    }
    cout << endl;
}

int main(){
    vector<int> vec;

    int input;
    cin >> input;

    while(input != -1){
        vec.push_back(input);
        cin >> input;
    }


    printVector(vec);

    vector<int>::iterator it = vec.begin();
    cout << *it << endl;
    vector<int>::iterator last = vec.end();
    cout << *(++last) << endl;

    cout << boolalpha;
    cout << isPresent(vec, 5) << endl;

    return 0;
}