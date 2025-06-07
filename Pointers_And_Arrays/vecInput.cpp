#include <iostream>
#include <vector>
using namespace std;

int main(){

    int size;
    cin >> size;

    vector<int> arr(size);
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    for(int& num : arr){
        cout << num << " ";
    }

    return 0;
}