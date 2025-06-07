#include <iostream>
#include <vector>
using namespace std;

int countDistinctElements(vector<int>& vec){
    

}

int main(){
    system("cls");

    vector<int> vec;

    int input;
    cin >> input;

    while(input != -1){
        vec.push_back(input);
        cin >> input;
    }

    cout << countDistinctElements(vec) << endl;

    return 0;
}