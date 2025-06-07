#include<iostream>
using namespace std;

int main()
{  
    int N;
    cin >> N;
    // int a = 0;
    // int b = 1;
    // int c = a + b;
    // int i = 0;
    // while(i < N - 3){
    //         a = b;
    //         b = c;
    //         c = a + b;
    //         ++i;
    // }
    // cout << c << endl;


    int x = 0; // first fibbonaci number
    int y = 1; // second fibbonaci number

    // printing the first fibbonaci number
    if(N > 0){
        cout << x << " ";
        N--;
    }

    // printing the second fibbonaci number
    if(N > 0){
        cout << y << " ";
        N--;
    }

    int z = 0;

    // do{
    //     z = x + y;
    //     x = y;
    //     y = z;
    //     cout << z << " ";
    // }while(--N);

    while(N--){
        z = x + y;
        cout << z << " ";
        x = y;
        y = z;
    }

    
    return 0;
}