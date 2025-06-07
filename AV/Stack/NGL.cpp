#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> NGL(vector<int>& arr){
    int n = arr.size();
    vector<int> v;
    stack<int> st;

    for(int i = )
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

    vector<int> ans = NGL(vec);
    for(int& num : ans){
        cout << num << " ";
    }
    cout << endl;





    return 0;
}