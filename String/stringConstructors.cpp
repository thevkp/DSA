#include <iostream>
#include <string>
using namespace std;

int main(){

    string one("Lottery Winner!"); //ctor #1
    cout << one << endl;
    cout << one[0] << endl;
    
    string two(20, '$'); //ctor #2
    cout << two << endl;

    // more on ctor #2 
    string rep(5, '*');
    cout << rep << endl;

    string three(one); //ctor #3
    cout << three << endl;
    cout << three[0] << endl;
    three[0] = 'P';
    cout << three << endl;

    one += " Oops!"; // #overloaded  +=
    cout << one << endl;

    string four;
    four = one + three; // overloaded =, +
    cout << four << endl;

    char alls[] = "All's well that ends well";
    cout << alls << endl;

    string five(alls, 20);  //ctor, #5
    cout << five << endl;

    string six(alls+6, alls+10); // ctor #6
    cout << six <<  endl;

    string seven(&five[6], &five[10]); //ctor #6 again
    cout << seven << endl;




    return 0;
}