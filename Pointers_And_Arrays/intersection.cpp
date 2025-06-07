#include <iostream>
#include <vector>
using namespace std;

//
vector<int> intersect(vector<int> arr1, vector<int> arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> result;
    int i = 0;
    while(i < n1){
        int j = 0;
        while(j < n2){
            if(arr2[j] == arr1[i]){
                result.push_back(arr1[i]);
            }
            j++;
        }
        i++;
    }

    return result;
}

int main(){
    system("cls");

    vector<int> arr1;
    vector<int> arr2;

    int input1, input2;
    cin >> input1;
    while(input1 != -1){
        arr1.push_back(input1);
        cin >> input1;
    }

    cin >> input2;
    while(input2 != -1){
        arr2.push_back(input2);
        cin >> input2;
    }

    vector<int> ans = intersect(arr1, arr2);
    for(int num : ans){
        cout << num << " ";
    }

    return 0;
}