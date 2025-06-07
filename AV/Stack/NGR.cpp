#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int ls(vector<int>& arr, int key){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int NGR(vector<int>& arr, int target){
    int n = arr.size();
    stack<int> st;


    int index = ls(arr, target);
    for(int i = n - 1; i > index; i--){
        st.push(arr[i]);
    }

    while(!st.empty()){
        if(st.top() <= target)
            st.pop();
        else if(st.top() > target)
            return st.top();
    }

    return -1;
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

    int target;
    cin >> target;

    cout << NGR(vec, target) << endl;


    return 0;
}