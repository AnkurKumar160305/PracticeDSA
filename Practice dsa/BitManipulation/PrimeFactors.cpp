#include <bits/stdc++.h>
using namespace std;

void printPrimeFactors(int n) {
    // Handle factor 2 separately
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }

    // Check odd factors up to sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    // If n is still greater than 1, it is prime
    if (n > 1)
        cout << n;
}

int main() {
    int n = 36;
    printPrimeFactors(n);
    return 0;
}
