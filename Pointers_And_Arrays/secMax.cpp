#include <iostream>
#include <vector>
#include <climits>
using namespace std;


// Naive approach
int secMax(vector<int>& arr){
    int max = arr[0];

    for(int& num : arr){
        if(max < num){
            max = num;
        }
    }

    int secMax = -1;
    for(int& num : arr){
        if(secMax < num && num != max){
            secMax = num;
        }
    }

    return secMax;
}

// Better approach
int secMaxBetter(vector<int>& arr){
    int max = INT_MIN;
    int secMax = INT_MIN;

    for(int& num : arr){
        if(max < num){
            secMax = max;
            max = num;
        }
        else if(secMax < num && num < max){
            secMax = num;
        }
    }

    return secMax == INT_MIN ? -1 : secMax;
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

    cout << secMax(vec) << endl;
    cout << secMaxBetter(vec) << endl;



    return 0;
}