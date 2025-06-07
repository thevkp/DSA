#include <iostream>
using namespace std;

const int MAX = 1000001;

bool isSubset(int* arr2, int* arr1, int n1, int n2){
    int freq[MAX] = {0};

    for(int i = 0; i < n2; i++){
        freq[arr2[i]]++;
    }

    for(int i = 0; i < n2; i++){
        cout << freq[i] << " ";
    }

    for(int i = 0; i < n1; i++){
        if(freq[arr1[i]] == 0)
            return false;
        freq[arr1[i]]--;
    }

    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n1, n2;
        cin >> n1;
        int* arr1 = new int[n1];
        for(int i = 0; i < n1; i++){
            cin >> arr1[i];
        }

        cin >> n2;
        int* arr2 = new int[n2];
        for(int i = 0; i < n2; i++){
            cin >> arr2[i];
        }

        if(isSubset(arr2, arr1, n1, n2))
            cout << "True" << endl;
        else
            cout << "False" << endl;

        delete[] arr1;
        delete[] arr2;
    }

    return 0;
}



// 3
// 5
// 1 2 3 5 6
// 9
// 9 8 5 6 3 2 1 4 7
// 1
// 2
// 5
// 3 6 5 4 1
// 7
// 1 2 3 5 6 8 9
// 3
// 9 8 2