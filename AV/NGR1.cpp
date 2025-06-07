#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> NGR(vector<int>& arr){
    vector<int> ans;
    stack<int> st;
    int n = arr.size();

    for(int i = n - 1; i >= 0; i--){
        if(st.empty()){
            ans.push_back(-1);
        }
        else if(st.size() > 0 && st.top() > arr[i]){
            ans.push_back(st.top());
        }
        else if(st.size() > 0 && st.top() 
    }
}


int main(){
    system("cls");



    return 0;
}