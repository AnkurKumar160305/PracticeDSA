class Solution {
    int countVowel(string &str){
        int cnt=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'){
                cnt++;
            }
        }
        return cnt;
    }

    void Reverse(string &str){
        int left=0,right=str.size()-1;
        while(left<right){
            swap(str[left++],str[right--]);
        }
    }
public:
    string reverseWords(string s) {
        int n=s.size();
        vector<string> arr;
        string word="";

        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                word+=s[i];
            }else if(word.size()>0){
                arr.push_back(word);
                word="";
            }
        }
        if(word.size()>0){
            arr.push_back(word);
        }

        int cnt=countVowel(arr[0]);
        for(int i=1;i<arr.size();i++){
            if(cnt==countVowel(arr[i])){
                Reverse(arr[i]);
            }
        }

        string ans="";
        for(int i=0;i<arr.size();i++){
            ans+=arr[i];
            if(i!=arr.size()-1){
                ans+=" ";
            }
        }
        return ans;
    }
};


//Optimal
class Solution {
    bool isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }

    int countVowel(string &s, int l, int r){
        int cnt = 0;
        for(int i = l; i <= r; i++){
            if(isVowel(s[i])) cnt++;
        }
        return cnt;
    }

    void Reverse(string &s, int l, int r){
        while(l < r){
            swap(s[l++], s[r--]);
        }
    }

public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;

        // 1️⃣ Find first word
        while(i < n && s[i] == ' ') i++;
        int firstStart = i;

        while(i < n && s[i] != ' ') i++;
        int firstEnd = i - 1;

        int firstVowelCount = countVowel(s, firstStart, firstEnd);

        // 2️⃣ Process remaining words
        while(i < n){
            while(i < n && s[i] == ' ') i++;
            if(i >= n) break;

            int l = i;
            while(i < n && s[i] != ' ') i++;
            int r = i - 1;

            if(countVowel(s, l, r) == firstVowelCount){
                Reverse(s, l, r);
            }
        }

        return s;
    }
};