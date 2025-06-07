#include <iostream>
using namespace std;

int main(){
    int numerator, denominator;
    
    cin >> numerator >> denominator;

    try{
        if(denominator == 0)
            throw runtime_error("Division by 0");

        cout << numerator/denominator << endl;
    }
    catch(const exception& f){
        cout << "Caught exception: " << f.what() << endl;
    }

    return 0;
}