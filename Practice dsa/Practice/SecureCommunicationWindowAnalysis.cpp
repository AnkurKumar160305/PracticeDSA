long long atMostK(string &s,int k){
    unordered_map<char,int> freq;
    long long cnt=0;
    int n=s.length();
    int l=0;
    for(int r=0;r<n;r++){
        freq[s[r]]++;
        while(freq.size()>k){
            freq[s[l]]--;
            if(freq[s[l]]==0){
                freq.erase(s[l]);
            }
            l++;
        }
        cnt+=(r-l+1);
    }
    return cnt;
}
long long countSecureWindows(string s) {
    return atMostK(s, 3) - atMostK(s, 2);
}