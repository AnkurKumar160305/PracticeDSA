//Using recursion
#include<bits/stdc++.h>

#define MOD 1000000007

long long int countDerangements(int n) {
    // Write your code here.
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    int ans=((n-1)%MOD)*((countDerangements(n-2)%MOD)+(countDerangements(n-1)%MOD));
    return ans;
}


//Using memoization
#include<bits/stdc++.h>
#define MOD 1000000007

int solve(int n,vector<int>& dp){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(dp[n]!=-1) return dp[n];
    
    long long a = solve(n - 2, dp);
    long long b = solve(n - 1, dp);

    dp[n] = ((n - 1LL) * ((a + b) % MOD)) % MOD;

    return dp[n];
}

long long int countDerangements(int n) {
    // Write your code here.
    vector<int> dp(n+1,-1);
    return solve(n,dp);
}

//Using tabulation
#include<bits/stdc++.h>
#define MOD 1000000007

long long int solve(int n){
    vector<long long int> dp(n+1,0);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++){
        long long int first=dp[i-1]%MOD;
        long long int second=dp[i-2]%MOD;
        long long int sum=(first+second)%MOD;
        long long int ans=((i-1)*sum)%MOD;
        dp[i]=ans;
    }
    return dp[n];
}

long long int countDerangements(int n) {
    // Write your code here.
    return solve(n);
}


//Space optimization
#include<bits/stdc++.h>
#define MOD 1000000007

long long int solve(int n){
    long long int prev2=0;
    long long int prev1=1;
    for(int i=3;i<=n;i++){
        long long int first=prev1%MOD;
        long long int second=prev2%MOD;
        long long int sum=(first+second)%MOD;
        long long int ans=((i-1)*sum)%MOD;
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}

long long int countDerangements(int n) {
    // Write your code here.
    return solve(n);
}