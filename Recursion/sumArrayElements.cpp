#include <iostream>
using namespace std;

int sum(int arr[], int n) {
    if(n == 0) return arr[n];

    return arr[n] +  sum(arr, n - 1);

}


int main(){
    system("cls");

    int size;
    cin >> size;

    int arr[size];

    int i = 0, input;
    cin >> input;
    while(i < size && input != -1){
        arr[i] = input;
        cin >> input;
        i++;
    }


    cout << sum(arr, size - 1);

    return 0;
}