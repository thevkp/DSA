#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void reverseWords(string &s) {
    // Step 1: Trim spaces (in-place)
    int n = s.size(), i = 0, j = 0;
    while (i < n && s[i] == ' ') i++;  // Skip leading spaces

    while (i < n) {
        // Copy non-space characters
        if (s[i] != ' ') s[j++] = s[i++];
        // For space, add one and skip extras
        else {
            s[j++] = ' ';
            while (i < n && s[i] == ' ') i++;
        }
    }

    // Remove trailing space if any
    if (j > 0 && s[j - 1] == ' ') j--;

    s.resize(j);  // Final trimmed string

    // Step 2: Reverse entire string
    reverse(s.begin(), s.end());
    cout << s << endl;

    // Step 3: Reverse each word
    int start = 0;
    for (int k = 0; k <= s.size(); ++k) {
        if (k == s.size() || s[k] == ' ') {
            reverse(s.begin() + start, s.begin() + k);
            start = k + 1;
        }
    }
}

int main(){
    system("cls");

    string input;
    getline(cin, input);

    reverseWords(input);
    cout << input << endl;



    return 0;
}


