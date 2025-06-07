#include <iostream>
using namespace std;

bool isPresent(int* arr, int size, int target){
    int front = 0;
    int back = size - 1;
    while(front <= back){
        if(arr[front] == target || arr[back] == target){
            return true;
        }
        front++;
        back--;
    }

    return false;
}

int main(){
    system("cls");

    int size, target;
    cin >> size >> target;

    int* arr = new int[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    cout << boolalpha;
    cout << isPresent(arr, size, target) << endl;

    delete[] arr;
    return 0;
}