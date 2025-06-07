#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int secondLargest(vector<int>& arr){
    int max = INT_MIN;
    int secMax = INT_MIN;

    for(int& num : arr)
    {
        if(num > max)
        {
            secMax = max;
            max = num;
        }
    }

    return secMax;
}


int main(){
    system("cls");

    vector<int> arr;
    
    int input;
    cin >> input;
    while(input != -1)
    {
        arr.push_back(input);
        cin >> input;
    }

    cout << secondLargest(arr) << endl;



    return 0;
}