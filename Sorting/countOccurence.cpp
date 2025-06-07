#include <iostream>
using namespace std;

int countKey(int* arr, int n, int key){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == key)
            count++;
    }

    return count;
}


int main(){
    system("cls");

    int size, key;
    cin >> size >> key;

    int* arr = new int[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    cout << countKey(arr, size, key) << endl;


    delete[] arr;
    return 0;
}