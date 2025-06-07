#include <iostream>
using namespace std;


bool reachHome(int s, int d){
    if(s == d){
        return true;
    }

    s += 3;
    return reachHome(s, d);
}


int main(){

    int dist, src;
    cin >> dist >> src;



    cout << boolalpha;
    cout << reachHome(src, dist) << endl;





    return 0;
}