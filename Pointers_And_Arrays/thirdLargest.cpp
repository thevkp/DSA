#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> largest123(vector<int>& arr){
    int max = INT_MIN;
    int secMax = INT_MIN;
    int thirdMax = INT_MIN;

    for(int& num : arr){
        if(max < num){
            thirdMax = secMax;
            secMax = max;
            max = num;
        }
        else if(secMax < num && num < max){
            thirdMax = secMax;
            secMax = num;
        }
        else if(thirdMax < num && num < secMax){
            thirdMax = num;
        }
    }

    if(thirdMax == INT_MIN)
        return {-1};

    return {max, secMax, thirdMax};
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


    vector<int> result = largest123(vec);
    for(int& num : result){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}