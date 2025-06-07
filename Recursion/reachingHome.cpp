#include <iostream>
using namespace std;

void reachHome(int src, int dest){
    // base/termination case
    if(src == dest){
        cout << "Reached." << endl;
        return;
    }

    reachHome(src - 1, dest);
}

int main(){
    system("cls");
    int destination = 10;
    int source = 1;

    reachHome(destination, source);

    return 0;
}