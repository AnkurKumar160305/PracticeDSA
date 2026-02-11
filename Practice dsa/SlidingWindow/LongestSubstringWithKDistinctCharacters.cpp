#include <bits/stdc++.h> 

int getLengthofLongestSubstring(string s, int k){
    unordered_map<char, int> freq;
    int n=s.length();
    int i=0;
    int maxi=0;

    for(int j=0;j<n;j++){
        freq[s[j]]++;
        while(freq.size()>k){
            freq[s[i]]--;
            if(freq[s[i]]==0){
                freq.erase(s[i]);
            }
            i++;
        }
        maxi=max(maxi,j-i+1);
    }
    return maxi;
}
    

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n=s.length();
        int i=0,j=0;
        vector<int> freq(26,0);
        int cnt=0;
        int maxi=-1;
        
        while(j<n){
            if(freq[s[j]-'a']==0){
                cnt++;
            }
            freq[s[j]-'a']++;
            while(cnt>k){
                freq[s[i]-'a']--;
                if(freq[s[i]-'a']==0){
                    cnt--;
                }
                i++;
            }
            if(cnt==k){
                maxi=max(maxi,j-i+1);
            }
            j++;
        }
        return maxi;
    }
};