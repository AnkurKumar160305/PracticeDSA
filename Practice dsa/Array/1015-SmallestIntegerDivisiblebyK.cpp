class Solution {
public:
    int smallestRepunitDivByK(int k) {
        long rev = 0;
        for (int i = 1; i <= k; i++) {
            rev = (rev * 10 + 1) % k;
            if (rev == 0) {
                return i;
            }
        }

        return -1;
    }
};