#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int>& s){
    stack<int> st1, st2;
    while(s.size() != 0){
        st1.push(s.top());
        s.pop();
    }
    while(st1.size() != 0){
        st2.push(st1.top());
        st1.pop();
    }
    while(st2.size() != 0){
        s.push(st2.top());
        st2.pop();
    }
}

int main(){
    system("cls");
    stack<int> st;
    int input;
    cin >> input;
    while(input != -1){
        st.push(input);
        cin >> input;
    }

    // while(st.size()){
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    reverseStack(st);
    while(st.size()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}