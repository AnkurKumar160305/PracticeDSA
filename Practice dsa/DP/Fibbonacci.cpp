//Fibbonacci Number
#include<bits/stdc++.h>
using namespace std;

//Top Down Approach
//Memoization+Recursion

// int fibb(int n,vector<int>& dp){
//         if(n<=1){
//                 return n;
//         }
//         if(dp[n]!=-1) return dp[n];

//         dp[n]=fibb(n-1,dp)+fibb(n-2,dp);

//         return dp[n];
// }
// int main()
// {
//         /*
//         *  Write your code here. 
//          *  Read input as specified in the question.
//          *  Print output as specified in the question.
//         */
//         int n;
//         cin>>n;
//         vector<int> dp(n+1,-1);

//         cout<<fibb(n,dp)<<endl;

//         return 0;
// }

//OR
//Tabulation Approach
//Bottom Up Approach
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

        dp[0]=0;
        dp[1]=1;

        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }

        cout<<dp[n]<<endl;

        return 0;
}


//Space optimization (Optimal Approach)
int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int n;
        cin>>n;

        int prev2=0;
        int prev1=1;

        for(int i=2;i<=n;i++){
            int curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }

        cout<<prev1<<endl;

        return 0;
}