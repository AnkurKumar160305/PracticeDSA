class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<int> ans;
        if(m>n){
            return ans;
        }
        vector<int> sFreq(26,0),pFreq(26,0);

        for(int i=0;i<m;i++){
            pFreq[p[i]-'a']++;
        }
        int i=0,j=0;
        while(j<n){
            sFreq[s[j]-'a']++;
            if(j-i+1>m){
                sFreq[s[i]-'a']--;
                i++;
            }
            if(j-i+1==m){
                if(pFreq==sFreq){
                    ans.push_back(i);
                }
            }
            j++;
        } 
        return ans;
    }
};


//Optimal
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<int> ans;
        if (m > n) return ans;

        vector<int> freq(26, 0);

        // frequency of pattern
        for (char c : p) {
            freq[c - 'a']++;
        }

        int i = 0, j = 0;
        int count = m;   // total chars needed

        while (j < n) {
            // include right char
            if (freq[s[j] - 'a'] > 0) {
                count--;
            }
            freq[s[j] - 'a']--;

            // window size reached
            if (j - i + 1 == m) {
                if (count == 0) {
                    ans.push_back(i);
                }

                // remove left char
                if (freq[s[i] - 'a'] >= 0) {
                    count++;
                }
                freq[s[i] - 'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};
"cbaebabacd"