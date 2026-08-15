#include <bits/stdc++.h> 

int solve(int i,vector<int>& nums,vector<int>& dp){
    if(i<0){
        return 0;
    }
    if(i==0){
        return nums[0];
    }
    if(dp[i]!=-1) return dp[i];

    int take=solve(i-2,nums,dp)+nums[i];
    int not_take=solve(i-1,nums,dp);

    dp[i]=max(take,not_take);
    return dp[i];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int> dp(n,-1);
    return solve(n-1,nums,dp);
}


//Using tabulation
#include <bits/stdc++.h> 

int solveTab(vector<int>& nums){
    int n=nums.size();
    vector<int> dp(n,0);

    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int incl=nums[i];
        if(i>=2){
            incl+=dp[i-2];
        }
        int excl=dp[i-1];
        dp[i]=max(incl,excl);
    }
    return dp[n-1];
    
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    return solveTab(nums);
}



//Space optimization
#include <bits/stdc++.h> 

int solve(vector<int>& nums){
    int n=nums.size();
    int prev2=0;
    int prev1=nums[0];
    for(int i=1;i<n;i++){
        int incl=prev2+nums[i];
        int excl=prev1;
        int ans=max(incl,excl);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
    
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    return solve(nums);
}