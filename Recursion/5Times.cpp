#include <iostream>
#include <string>
using namespace std;

void times(string& str, int count){
    if(!count)
        return;
    
    cout << str << endl;
    times(str, count - 1);
}

int main(){
    string name;
    cin >> name;
    int count;
    cin >> count;
    times(name, count);


    return 0;
}