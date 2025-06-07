#include <stdio.h>
// using namespace std;


int main(){
    int num;
    scanf("%d", &num);
    
    printf("%d", num % 9 ? num % 9 : num ? 9 : 0);


    return 0;
}