#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& nums){
    for(int i = nums.size() - 1; i >= 0; i--){
        if(nums[i] < 9){
            nums[i]++;
            return nums;
        }
        nums[i] = 0;
    }
    nums.insert(nums.begin(), 1);
    return nums;
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

    vector<int> result = plusOne(arr);

    for(int num : result){
        cout << num << " ";
    }
    cout << endl;


    return 0;
}