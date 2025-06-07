#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int>& s){
    stack<int> temp;
    while(s.size()){
        temp.push(s.top());
        s.pop();
    }

    int ans = 0;
    while(temp.size()){
        ans = ans * 10 + temp.top();
        temp.pop();
    }
    cout << ans << endl;

    while(ans){
        s.push(ans%10);
        ans /= 10;
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