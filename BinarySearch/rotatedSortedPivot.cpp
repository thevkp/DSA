#include <iostream>
#include <vector>
using namespace std;


int findPivot(vector<int>& arr){
    int start = 0;
    int end = arr.size() - 1;

    while(start < end){
        int mid = start + (end - start) / 2;

        if(arr[mid] < arr[end]) 
            end = mid;
        else
            start = mid + 1;
    }

    return start;
}

int main(){
    system("cls");

    vector<int> arr;

    int input;
    cin >> input;

    while(input != -1){
        arr.push_back(input);
        cin >> input;
    }


    cout << "Idex of rotation: " << findPivot(arr) << endl;



    return 0;
}