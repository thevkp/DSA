#include <iostream>
#include <vector>
using namespace std;

void plusOne(vector<int>& nums){
    int n = nums.size();
    int end = n - 1;
    int lastElement = nums[end] + 1;

    while(lastElement){
        if(lastElement >= 10){
            nums.pop_back();
            nums.push_back(lastElement / 10);
            nums.push_back(lastElement % 10);
        }
        else{   
            nums.pop_back();
            nums.push_back(lastElement);
        }
        lastElement /= 10;
    }
}


int main(){
    system("cls");
    vector<int> arr;
    int input;
    cin >> input;
    while(input != -1){
        arr.push_back(input);
        cin >> input;
    }

    plusOne(arr);

    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;


    return 0;
}