class Solution {
    vector<vector<int>> dp;
    int solve(string &text1,string &text2,int n1,int n2){
        if(n1<0 || n2<0){
            return 0;
        }
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        if(text1[n1]==text2[n2]){
            dp[n1][n2]=1+solve(text1,text2,n1-1,n2-1);
        }else{
            dp[n1][n2]=max(solve(text1,text2,n1,n2-1),solve(text1,text2,n1-1,n2));
        }

        return dp[n1][n2];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        dp.assign(n1,vector<int>(n2,-1));
        return solve(text1,text2,n1-1,n2-1);
    }
};


//Tabulation Form
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }

            }
        }

        return dp[n][m];
    }
};