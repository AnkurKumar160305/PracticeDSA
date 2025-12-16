

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        int start = 0;  
        int maxLen = 1; 

        for (int i = 0; i < n; ++i) {
            // odd-length palindromes (center at i)
            expandAroundCenter(s, i, i, start, maxLen);

            // even-length palindromes (center between i and i+1)
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    // expands from left and right; updates start and maxLen by reference
    void expandAroundCenter(const string &s, int left, int right, int &start, int &maxLen) {
        int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right]) {
            int len = right - left + 1;
            if (len > maxLen) {
                start = left;
                maxLen = len;
            }
            --left;
            ++right;
        }
    }
};
