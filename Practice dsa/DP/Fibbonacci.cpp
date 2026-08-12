#include<bits/stdc++.h>
using namespace std;

int fibb(int n,vector<int>& dp){
        if(n<=1){
                return n;
        }
        if(dp[n]!=-1) return dp[n];

        dp[n]=fibb(n-1,dp)+fibb(n-2,dp);

        return dp[n];
}

int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int n;
        cin>>n;
        vector<int> dp(n+1,-1);

        cout<<fibb(n,dp)<<endl;

        return 0;
}