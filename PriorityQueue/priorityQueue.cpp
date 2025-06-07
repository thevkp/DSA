#include <iostream>
#include <queue>
using namespace std;


int main(){
    system("cls");

    priority_queue<int> pq;

    int input;
    cin >> input;

    while(input != -1){
        pq.push(input);
        cin >> input;
    }

    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;


    return 0;
}