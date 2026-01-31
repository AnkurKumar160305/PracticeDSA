class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal;   // XOR to find differing bits
        int count = 0;

        // Count set bits (Brian Kernighan’s Algorithm)
        while (x) {
            x &= (x - 1);
            count++;
        }

        return count;
    }
};
