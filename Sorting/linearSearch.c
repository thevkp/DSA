#include <stdio.h>
#include <stdlib.h>

int linearSearch(int* arr, int* n, int target){
    for(int i = 0; i < *n; i++){
        if(arr[i] == target)
            return i;
    }

    return -1;
}

int main(){
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }


    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n%d", linearSearch(arr, &n, 4));

    free(arr);
    return 0;
}