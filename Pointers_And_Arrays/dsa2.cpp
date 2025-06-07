#include <iostream> 
using namespace std;

int main(){
    system("cls");
    int arr[] = {1, 2, 3}, *p = arr;
    int size = sizeof(arr) /  sizeof(arr[0]);

    // *p++;
    (*p)++;

    for(int i = 0; i < size; i++){
        cout <<  arr[i] << " ";
    }
    

    return 0;
}