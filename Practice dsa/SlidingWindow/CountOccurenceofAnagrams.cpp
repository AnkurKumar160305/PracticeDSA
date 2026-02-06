// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
        // code here
        int k=pat.size();
        int n=txt.size();
        int cnt=0;
        if(k>n){
            return 0;
        }
        vector<int> patFreq(26,0);
        vector<int> txtFreq(26,0);
        for(auto i:pat){
            patFreq[i-'a']++;
        }
        int i=0,j=0;
        while(j<n){
            txtFreq[txt[j]-'a']++;
            if(j-i+1>k){
                txtFreq[txt[i]-'a']--;
                i++;
            }
            if(j-i+1==k){
                if(patFreq==txtFreq){
                    cnt++;
                }
            }
            j++;
        }
        return cnt;
    }
};