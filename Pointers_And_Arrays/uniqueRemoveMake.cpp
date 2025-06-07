#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


// takes linear space
int minElements(int arr[], int size){
	unordered_map<int,int> freqMap;
	
	for(int i = 0; i < size; i++){
		freqMap[arr[i]]++;
	}

	int min = 0;
	for(const auto& it : freqMap){
		if(it.second > 1){
			min += it.second - 1;
		}
	}
	return min;
}


// takes constant space but time complexity is O(nlogn)
int minRemovals(int arr[], int size){
	sort(arr, arr + size);

	int minElements = 0;
	for(int i = 1; i < size; i++){
		if(arr[i - 1] == arr[i])
			minElements++;
	}

	return minElements;
}


int main(){
	int size;
	cin >> size;
	
	int* arr = new int[size];
	
	int input;

	for(int i = 0; i < size; i++){
		// cin >> input;
		// arr[i] = input;	
		cin >> arr[i];
	}
	
	cout << minElements(arr, size) << endl;
	cout << minRemovals(arr, size) << endl;
	
	delete[] arr;
	return 0;
}