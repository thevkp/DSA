#include <iostream>
#include <vector>
using namespace std;

int removeDuplicate(vector<int>& arr){
    int n = arr.size();
    int i = 0;
    for(int j = 1; j < n; j++){
        if(arr[i] != arr[j]){
            arr[++i] = arr[j];
        }
        j++;
    }

    return i + 1;
}

int main(){
    system("cls");
    int size;
    cin >> size;

    vector<int> vec(size);
    for(int i = 0; i < size; i++){
        cin >> vec[i];
    }

    int n = removeDuplicate(vec);

    for(int i = 0; i < n; i++){
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}