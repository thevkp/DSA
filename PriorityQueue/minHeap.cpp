#include <iostream>
#include <queue>
using namespace std;


int main(){
    system("cls");

    priority_queue<int, vector<int>, greater<int>> pq;

    int input;
    cin >> input;

    while(input != -1){
        pq.push(input);
        cin >> input;
    }


    cout << pq.top() << endl;
    cout << pq.size() << endl;



    return 0;
}