#include <iostream>
using namespace std;

char exCeil(char* arr, int size, char key){
    int start = 0;
    int end = size - 1;

    char xCeil = ' ';
    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid] > key){
            xCeil = arr[mid];
            end  = mid - 1;
        }
        else
            start = mid + 1;
    }

    return xCeil;
}


int main(){
    int size;
    cin >> size;

    char* arr = new char[size];

    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    char target;
    cin >> target;

    cout << exCeil(arr, size, target) << endl;


    delete[] arr;
    return 0;
}