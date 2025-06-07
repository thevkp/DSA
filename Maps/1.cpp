/*
1.)std::map: syntax map<T1, T2> obj; T1 & T2 are data type
          T1 is key and T2 is value
2.)std::map is an associative container that stores elements in 
key value pair, where key should be otherwise previous key will
be overriden
3.)std::map is implented using a BST(specially a red-black tree)
4.)std::map stores elements(key-value pairs) in sorted order
5.)std::map is generally used in dictionary type problems

6.)Time complexities:
    insertion, deletion, acces(find(), []): average O(logn), worst O(logn)
    traversal using iterators: O(n);
    size(): O(1)

*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){ 
    map<char, int> mp;

    mp['a'] = 1;
    mp['b'] = 2;
    mp['a'] = 3; // updates the value(eg. 1 to 3)

    // using insert(make_pari{key, value})
    mp.insert(make_pair('c', 4));

    // using emplace(.emplace(key, value))
    mp.emplace('d', 5);
    mp.insert(make_pair('c', 5));

    // inserting multiple items
    mp.insert({{'e', 6}, {'f', 7}});

    // // using insert_or_assign(key, value)
    // mp.insert_or_assign(make_pair();

    for(const auto& pair : mp){
        cout << pair.first << " " << pair.second << endl;
    }



    return 0;
}
