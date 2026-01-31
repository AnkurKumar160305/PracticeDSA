#include <bits/stdc++.h>
using namespace std;


| n | XOR(1..n)           |
| - | ------------------- |
| 1 | `1`                 |
| 2 | `1 ^ 2 = 3`         |
| 3 | `1 ^ 2 ^ 3 = 0`     |
| 4 | `1 ^ 2 ^ 3 ^ 4 = 4` |
| 5 | `1`                 |
| 6 | `7`                 |
| 7 | `0`                 |
| 8 | `8`                 |
🔁 Pattern repeats every 4 numbers!

class Solution {
private:
    /* Function to find the XOR 
    of numbers from 1 to n*/
    int XORtillN(int n) {
        if(n % 4 == 1) return 1;
        if(n % 4 == 2) return n+1;
        if(n % 4 == 3) return 0;
        return n;
    }
    
public:
    /* Function to find the XOR 
    of numbers from L to R*/
    int findRangeXOR(int l, int r){		
        // XOR from L to R = XOR(1 to R) ^ XOR(1 to L-1)	
		return XORtillN(l-1) ^ XORtillN(r);
	}
};

int main() {
    int l = 3, r = 5;
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to get the
    XOR of numbers from L to R*/
    int ans = sol.findRangeXOR(l, r);
    
    cout << "The XOR of numbers from " << l << " to " << r << " is: " << ans;
    
    return 0;
}
