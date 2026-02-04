// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
        int k = pat.size();
        int n = txt.size();
        if(k > n) return 0;
        
        vector<int> patFreq(26,0),txtFreq(26,0);
        for(int i=0;i<pat.size();i++){
            patFreq[pat[i]-'a']++;
        }
       
        
        int cnt=0;
        for(int i=0;i<n;i++){
            txtFreq[txt[i]-'a']++;
            if(i>=k){
                txtFreq[txt[i-k]-'a']--;
            }
            if(i>=k-1 && txtFreq==patFreq){
                cnt++;
            }
        }
        return cnt;
        
    }
};