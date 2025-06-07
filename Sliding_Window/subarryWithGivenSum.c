#include <stdio.h>
#include <stdlib.h>



int main(){
    int size, target;
    scanf("%d %d", &size, &target);

    int* arr = (int*)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        scanf("%i", &arr[i]);
    }



    free(arr);

    return 0;
}