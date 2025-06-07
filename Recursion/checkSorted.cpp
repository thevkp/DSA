#include <iostream>
using namespace std;

bool sorted(int* arr, int start, int end){
    
}

int main(){
    system("cls");

    int size;
    cin >> size;

    int* arr = new int[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    cout << boolalpha;
    cout << sorted(arr, 1, size - 1) << endl;

    return 0;
}