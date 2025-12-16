class Solution {

    int isValid(string str){
        unordered_map<char,int> m;
        for(char c:str){
            m[c]++;
        }
        int maxi=0,mini=INT_MAX;
        for(auto i:m){
            maxi=max(maxi,i.second);
            mini=min(mini,i.second);
        }
        return maxi-mini;
    }
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                ans+=isValid(s.substr(i,j-i+1));
            }
        }
        return ans;

    }
};


//Optimal
class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> freq(26, 0);
            for(int j=i;j<n;j++){
                freq[s[j] - 'a']++;
                int maxi = 0;
                int mini = INT_MAX;

                for(int k = 0; k < 26; k++){
                    if(freq[k] > 0){
                        maxi = max(maxi, freq[k]);
                        mini = min(mini, freq[k]);
                    }
                }
                ans += maxi - mini;
            }
        }
        return ans;

    }
};