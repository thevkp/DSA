#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    int t;  // number of test cases
    cin >> t;
    
    // Get the testcases from the user
    vector<array<double,3>> testcases(t);
    for (auto& arr : testcases)
        cin >> arr[0] >> arr[1] >> arr[2];
        
    for (const auto& arr : testcases)
    {
        const double A = arr[0];
        const double B = arr[1];
        const double C = arr[2];
        
        cout << hex << left << showbase << nouppercase << (long long)A << endl;

        cout << dec << right << setw(15) << setfill('_') << showpos << fixed << setprecision(2) << B << endl;

        cout << scientific << uppercase << noshowpos << setprecision(9) << C << endl;
    }
    return 0;
}