#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printQueue(queue<int> q){
    for(int i = 0; i < q.size(); i++){
        cout << q.front() + i << " ";
        // q.pop();
    }
}

vector<int> firstNegatives(vector<int>& arr, int k){
    vector<int> ans;
    queue<int> q;

    for(int i = 0; i < k; i++){
        if(arr[i] < 0){
            q.push(i);
        }
    }

    cout << "Queue: ";
    printQueue(q);
    cout << endl;


    if(!q.empty()){
        ans.push_back(arr[q.front()]);
    }
    else{
        ans.push_back(0);
    }

    for(int i = k; i < arr.size(); i++){
        while(!q.empty() && q.front() <= i - k){
            q.pop();
        }

        
        if(arr[i] < 0){
            q.push(i);
        }

        cout << "Queue: ";
        printQueue(q);
        cout << endl;   

        if(!q.empty()){
            ans.push_back(arr[q.front()]);
        }
        else{
            ans.push_back(0);
        }
    }


    return ans;
}


int main(){
    system("cls");

    int n;
    cin >> n;

    vector<int> vec(n);

    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    int k;
    cin >> k;

    vector<int> result = firstNegatives(vec, k);
    for(int& num : result){
        cout << num << " ";
    }
    cout << endl;




    return 0;
}


// 8 
// 12 -1 -7 8 -15 30 16 -28
// 3