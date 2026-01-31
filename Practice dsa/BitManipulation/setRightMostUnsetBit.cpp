#include <bits/stdc++.h>
using namespace std;

// Function to set the rightmost unset bit (0 -> 1)

int setRightmostUnsetBit(int n) {
    // If all bits are already set, return n unchanged
    if ((n & (n + 1)) == 0)
        return n;

    // Otherwise, set the rightmost unset bit
    return n | (n + 1);
}

int main() {
    int n = 7;  // binary: 111

    cout << setRightmostUnsetBit(n) << endl;
    return 0;
}
