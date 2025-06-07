#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void negativesPositives(vector<int>& arr){
    int n = arr.size();
    int i = 0;
    for(int j = 1; i < n - 1; j++){
        if(arr[j] < 0){
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

void sorteActualValues(vector<int>& arr){
    deque<int> dq;

    for(int& num : arr){
        if(num < 0){
            dq.push_front(num);
        }
        else{
            dq.push_back(num);
        }
    }
    arr.clear();
    arr.insert(arr.begin(), dq.begin(), dq.end());
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

    sorteActualValues(vec);
    for(int& num : vec){
        cout << num << " ";
    }
    cout << endl;


    return 0;
}