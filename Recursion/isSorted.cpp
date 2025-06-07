#include <iostream>
using namespace std;

bool isSorted(int *arr, int n){

    if(n == 0 || n == 1)
        return true;
    
    if(arr[0] > arr[1])
        return false;
    else{
        bool sorted = isSorted(arr + 1, n - 1);
        return sorted;
    }
}


int main(){
    system("cls");

    int size;
    cin >> size;
    // if(size < 0){
    //     cout << "Invalid size" << endl;
    //     return 0;
    // }
    // if(size == 0){
    //     cout << boolalpha;
    //     cout << true << endl;
    //     return 0;
    // }
    // if(size == 1){
    //     cout << boolalpha;
    //     cout << true << endl;
    //     return 0;
    // }

    int *arr = new int[size];

    int input;
    cin >> input;
    int i = 0;
    while(i < size && input != -1){
        arr[i] = input;
        cin >> input;
        i++;
    }

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << boolalpha;
    cout << isSorted(arr, i) << endl;
    cout << isSorted1(arr, i) << endl;

    return 0;
}