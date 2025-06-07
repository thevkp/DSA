#include <iostream>
#include <map>
using namespace std;

int main(){
    // system("cls");

    map<string, int> mp;
    string name;
    int marks, n;

    cin >> n;
    for(int i = 0; i < n; i++){
        int q;
        cin >> q;
        if(q == 1){
            cin >> name >> marks;
            mp[name] = marks;
        }
        else if(q == 2){
            cin >> name;
            if(mp.find(name) != mp.end()){
                mp.erase(name);
            }
            else 
                cout << name << " not found" << endl;
        }
        else if(q == 3){
            cin >> name;
            if(mp.find(name) != mp.end()){
                cout << mp[name];
            }
        }
        else 
            cout << 0;
    }


    return 0;
}