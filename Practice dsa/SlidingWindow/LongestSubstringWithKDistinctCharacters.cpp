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
    