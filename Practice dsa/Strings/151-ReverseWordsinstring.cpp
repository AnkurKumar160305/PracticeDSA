class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int left=0,right=n-1;
        while(left < n && s[left] == ' ') left++;
        while(right >= 0 && s[right] == ' ') right--;
        if(left > right) return "";

        string res = s.substr(left, right - left + 1);
        n = res.size();

        reverse(res.begin(), res.end());

         // 3️⃣ Reverse each word
        int i = 0;
        while(i < n){
            if(res[i] != ' '){
                int j = i;
                while(j < n && res[j] != ' ') j++;
                reverse(res.begin() + i, res.begin() + j);
                i = j;
            } else {
                i++;
            }
        }

        // 4️⃣ Remove extra spaces between words
        string ans = "";
        for(int i = 0; i < n; i++){
            if(res[i] != ' ' || (i > 0 && res[i-1] != ' '))
                ans += res[i];
        }

        return ans;
    }
};