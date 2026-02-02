// You are given an integer n.

// An integer is called Monobit if all bits in its binary representation are the same.

// Return the count of Monobit integers in the range [0, n] (inclusive).


class Solution {
public:
    int countMonobit(int n) {
        int cnt=1;
        int val=1;
        while(val<=n){
            cnt++;
            val = (val<<1) | 1;
        }
        return cnt;
    }
};