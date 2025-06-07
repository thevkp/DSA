#include <iostream>
using namespace std;


// if the array is sorted
int count(int arr[], int n) {
    int count = 0;
    for(int i = 0; i < n - 1; i++){
        if(arr[i] == arr[i + 1])
            count++;
    }

    return count;
}

int main(){
    system("cls");

    int size;
    cin >> size;

    int arr[size];
    int input;
    cin >> input;
    int i = 0;
    while(i < size && input != -1) {
        arr[i] = input;
        cin >> input;
        i++;
    }

    cout << count(arr, size) << endl;

    return 0;
}