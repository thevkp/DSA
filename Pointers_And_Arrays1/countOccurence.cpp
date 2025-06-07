#include <iostream>
#include <vector>
using namespace std;

int occurence(vector<char>& str, char key, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == key)
            count++;
    }

    return count;
}


int main(){
    system("cls");
    vector<char> str;
    int size;
    cin >> size;
    char ch;
    for(int i = 0; i < size; i++){
        cin >> ch;
        str.push_back(ch);
    }

    char key;
    cin >> key;

   
    cout << occurence(str, key, size) << endl;

    return 0;
}