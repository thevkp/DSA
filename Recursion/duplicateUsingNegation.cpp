#include <iostream>
#include <vector>
using namespace std;

vector<int> duplicates(vector<int> arr){
    int n = arr.size();
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int index = abs(arr[i]) - 1;

        if(arr[index] < 0)
            ans.push_back(abs(arr[i]));
        else
            arr[index] = -arr[index];
    }

    return ans;
}

int main(){
    system("cls");

    vector<int> arr;
    int input;
    cin >> input;
    while(input != -1){
        arr.push_back(input);
        cin  >> input;
    }

    vector<int> result = duplicates(arr);
    for(int num : result){
        cout << num << " ";
    }

    return 0;
}

// example test cases
// 4 3 2 7 8 2 3 1 -1
// 10 2 5 10 9 1 1 4 3 7 -1