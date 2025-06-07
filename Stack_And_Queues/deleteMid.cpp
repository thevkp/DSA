#include <iostream>
#include <stack>
using namespace std;


void solve(stack<int>& stac, int count, int size){
    if(count == size / 2){
        stac.pop();
        return;
    }

    int topElement = stac.top();
    stac.pop();

    // recursively calling solve
    solve(stac, count + 1, size);

    stac.push(topElement);
}


void deleteMid(stack<int>& inputStack, int N){
    int count = 0;
    solve(inputStack, count, N);
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

    deleteMid(st, st.size());

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}