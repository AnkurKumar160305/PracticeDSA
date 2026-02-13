#include <bits/stdc++.h>
using namespace std;

string gcdOfStrings(string str1, string str2) {
    
    // Step 1: Check if valid
    if (str1 + str2 != str2 + str1)
        return "";
    
    // Step 2: Find gcd of lengths
    int len = gcd(str1.length(), str2.length());
    
    // Step 3: Return prefix of gcd length
    return str1.substr(0, len);
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    
    cout << gcdOfStrings(str1, str2);
}