#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
    // string s1 = "abc";
    // string s2 = "xyz";

    // cout << s1.append(s2) << endl;
    // cout << s1.find('a') << endl;
    // // s1.clear();
    // cout << s1 << endl;
    // // s1.insert('j', 2);
    // // cout << s1(10, 'a')<< endl;

    // string str(10, 'a');
    // cout << str << endl;

    // cout << s1.find('b') << endl;
    // cout << s1.length() << endl;
    // cout << boolalpha;
    // cout << s1.empty() << endl;
    // cout << s1.at(2) << endl;
    // cout << s1[2] << endl;

    // s1.append("jkl");
    // cout << s1 << endl;
    // s1.push_back('u');
    // cout << s1 << endl;
    // s1.pop_back();
    // cout << s1 << endl;

    // s1.insert(3, "Alecc");
    // cout << s1 << endl;
    // s1.erase(3, 3);
    // cout << s1 << endl;

    // s1.replace(3, 3, "Ale");
    // cout << "Here" << s1 << endl;
    // s1.insert(6, "cc");
    // cout << s1.substr(3, 5) << endl;

    // cout << s1.find('e') << endl;
    // cout << s1.rfind('e') << endl;

    // cout << boolalpha;
    // cout << s1.compare(s2) << endl;

    // string str;
    // cin >> str;

    // cout << str[(str.find(str[3]))]<< endl;

    // string temp;
    // temp.resize(str.size());
    // transform(str.begin(), str.end(), temp.begin(), ::tolower);
    // cout << str << endl;
    // cout << temp << endl;
    // // string temp = str;
    // // reverse()

    // cout << str.substr(0, 1) << endl;
    // cout << temp.substr(0, 1) << endl;

    // cout << str.substr(1, 2) << endl;
    // cout << temp.substr(1, 2) << endl;


    // cout << str.substr(3, 1) << endl;
    // cout << temp.substr(3, 1) << endl;


    string str = "butter";
    cout << to_string(str[0] - 32) << endl;

    cout << 'z' - 32 << endl;

    return 0; 
}