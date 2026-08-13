#include <bits/stdc++.h> 
#define MOD 1000000007

int solve(long long nStair,int i){
    if(i==nStair){
        return 1;
    }
    if(i>nStair){
        return 0;
    }

    return (solve(nStair,i+1)+solve(nStair,i+2))%MOD;
}

int countDistinctWays(int nStairs) {
    //  Write your code here.
    int ans=solve(nStair,0);
    return ans;
}

//Optimal DP
#include <bits/stdc++.h> 
#define MOD 1000000007

int countDistinctWays(int nStairs) {
    //  Write your code here.
    vector<int> dp(nStairs+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=nStairs;i++){
        dp[i]=(dp[i-1]+dp[i-2])%MOD;
    }
    return dp[nStairs];
}