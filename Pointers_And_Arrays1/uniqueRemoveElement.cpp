#include <iostream>
using namespace std;


int removeElement(int arr[], int n, int k){
    int i = 0;
    for(int j = 0; j < n; j++){
        if(arr[j] != k){
            arr[i] = arr[j];
            i++;
        }
    }
    return i;
}


int main(){
    system("cls");
    int size;
    cin >> size;

    int* arr = new int[size];

    int input;
    for(int i = 0; i < size; i++){
        cin >> input;
        arr[i] = input;
    }

    int k;
    cin >> k;

    cout << removeElement(arr, size, k) << endl;

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}