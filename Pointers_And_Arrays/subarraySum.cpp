#include <iostream>
using namespace std;

int subarrayLength(int* arr, int size, int target){
    long long int count_len = 0;
    long long int max_len = 0;
    long long int sum = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
        // cout << sum << endl;
        if(sum <= target){
            count_len = count_len + 1;
            max_len = count_len > max_len ? count_len : max_len;
            // cout << max_len << endl;
        }
        else if(sum > target){
            count_len = 0;
            sum = 0;
        }
    }

    return max_len;
}

int main(){
    int size, target;
    cin >> size >> target;

    int* arr = new int[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    cout << subarrayLength(arr, size, target) << endl;


    delete[] arr;

    return 0;
}