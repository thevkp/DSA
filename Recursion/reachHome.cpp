#include <iostream>
using namespace std;

void reachHome(int src, int dest){
    if(src == dest) {
        cout << "Reached" << endl;
        return;
    }
    reachHome(src + 1, dest);
}

int reachHomeSteps(int dest){
    if(dest < 0) return 0;
    if(dest == 0) return 1;

    return reachHomeSteps(dest - 1) + reachHomeSteps(dest - 2) + reachHomeSteps(dest - 3);
}

int main(){
    system("cls");

    int dest = 10;
    int src = 1;

    reachHome(src, dest);
    cout << reachHomeSteps(dest) << endl;

    return 0;
}
