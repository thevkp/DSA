#include <iostream>
#include <vector>
using namespace std;


void sort01(vector<int>& arr){
    int n = arr.size();
    int i = 0;
    int k = n - 1;
    for(int j = 0; j < n; j++){
        if(arr[j] == 0){
            swap(arr[i], arr[j]);
            i++;
            k = i + 1;
        }
        if(arr[j] == 2){
            swap(arr[j], arr[k]);
            k--;
        }
    }
}

int main(){
    system("cls");

    vector<int> vec;

    int input;
    cin >> input;

    while(input != -1){
        vec.push_back(input);
        cin >> input;
    }

    sort01(vec);

    for(int& num : vec){
        cout << num << " ";
    }
    cout << endl;


    return 0;
}