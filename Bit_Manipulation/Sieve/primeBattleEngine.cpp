#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;

bool isPrime_SquareCheck(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

bool isPrime_SqrtCheck(int n) {
    if (n < 2) return false;
    int limit = sqrt(n); // Compute once
    for (int i = 2; i <= limit; ++i)
        if (n % i == 0) return false;
    return true;
}

int countPrimes(bool (*isPrime)(int), int N) {
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        if (isPrime(i)) count++;
    }
    return count;
}

int main() {
    int N = 1e6;

    // Method 1: i * i <= n
    auto start1 = high_resolution_clock::now();
    int count1 = countPrimes(isPrime_SquareCheck, N);
    auto end1 = high_resolution_clock::now();

    // Method 2: i <= sqrt(n)
    auto start2 = high_resolution_clock::now();
    int count2 = countPrimes(isPrime_SqrtCheck, N);
    auto end2 = high_resolution_clock::now();

    cout << "Primes found: " << count1 << endl;

    auto duration1 = duration_cast<milliseconds>(end1 - start1).count();
    auto duration2 = duration_cast<milliseconds>(end2 - start2).count();

    cout << "[i * i <= n] Time: " << duration1 << " ms" << endl;
    cout << "[i <= sqrt(n)] Time: " << duration2 << " ms" << endl;

    return 0;
}
