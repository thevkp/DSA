    #include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> NGR(vector<int>& arr){
    int n = arr.size();
    vector<int> v;
    stack<int> st;

    for(int i = n - 1; i >= 0; i--){
        if(st.empty())
            v.push_back(-1);
        else if(st.size() > 0 && st.top() > arr[i])
            v.push_back(st.top());
        else if(st.size() > 0 && st.top() <= arr[i]){
            while(st.size() > 0 && st.top() <= arr[i]){
                st.pop();
            }

            if(st.empty())
                v.push_back(-1);
            else
                v.push_back(st.top());
        }
        st.push(arr[i]);
    }

    reverse(v.begin(), v.end());
    return v;
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

    vector<int> ans = NGR(vec);
    for(int& num : ans){
        cout << num << " ";
    }



    return 0;
}