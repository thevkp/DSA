#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int start, int mid, int end){
    int n1 = mid - start + 1;
    int n2 = end - start;

    int left[n1];
    int right[n2];

    for(int i = 0; i < n1; i++){
        left[i] = arr[start + i];
    }

    for(int j = 0; j < n2; j++){
        right[j] = arr[mid + j + 1];
    }

    int i = 0, j = 0, k = start;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int* arr, int start, int end){
    if(start >= end)
        return;

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void twoSum(int* arr, int n, int target, int* ans){
    mergeSort(arr, 0, n - 1);

    int start = 0;
    int end = n - 1;
    while(start < end && end >= 0){
        int sum = arr[start] + arr[end];

        if(sum == target){
            ans[0] = arr[start];
            ans[1] = arr[end];
            return;
        }
        else if(sum > target)
            end--;
        else 
            start++;
    }

    ans[0] = -1;
    ans[1] = -1;
}

int main(){
    int size, target;
    scanf("%d %d", &size, &target);

    int* arr = (int*)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    int ans[2];
    twoSum(arr, size, target, ans);
    printf("%d %d", arr[0], arr[1]);


    free(arr);

    return 0;
}