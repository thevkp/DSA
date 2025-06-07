#include <iostream>
#include <algorithm>  // For find() function
using namespace std;

int main() {
    int arr[] = {4, 2, 7, 1, 9, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    // Use std::find() to search for the target
    if (find(arr, arr + size, target) != arr + size) {
        cout << target << " is present in the array." << endl;
    } else {
        cout << target << " is not present in the array." << endl;
    }

    return 0;
}
