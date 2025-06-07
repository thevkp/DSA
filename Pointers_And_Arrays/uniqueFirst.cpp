#include <iostream>
#include <map>
using namespace std;

int firstUnique(int arr[], int n){
	map<int, int> freqMap;
	for(int i = 0; i < n; i++){
		freqMap[arr[i]]++;
	}
	
	for(const auto& it : freqMap){
		if(it.second == 1)
			return it.first;
	}
		
	return -1;
}


int main(){
	int size;
	cin >> size;

	int* arr = new int[size];
	
	int input;
	for(int i = 0; i < size; i++){
		cin >> input;
		arr[i] = input;
	}

	cout << firstUnique(arr, size) << endl;
	
	return 0;

}