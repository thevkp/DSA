#include <stdio.h>

int main(){
    const int num = 10;
    int* ptr = (int*)&num;
    *ptr = 20;
    printf("%d\n", num);

    return 0;
}