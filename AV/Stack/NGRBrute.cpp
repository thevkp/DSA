#include <iostream>
#include <vector>
using namespace std;

int NGR(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[j] > arr[i])
                return arr[j];
        }
    }

    return -1;
}

vector<int> NGR1(vector<int>& arr){
    int n = arr.size();
    vector<int> ans;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[j] > arr[i]){
                ans.push_back(arr[j]);
                break;
            }
        }
    }
    ans.push_back(-1);
    return ans;
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

    cout << NGR(vec) << endl;

    vector<int> GR = NGR1(vec);
    for(int& num : GR){
        cout << num << " ";
    }
    cout << endl;


    return 0;
}