#include <bits/stdc++.h> 

vector<vector<int>> dp;
int solve(int index,vector<int>& num,int target){
    if(target==0){
        return 0;
    }
    if(index==0){
        if(target%num[0]==0){
            return target/num[0];
        }
        return 1e9;
    }
    if(dp[index][target]!=-1) return dp[index][target];

    int take=1e9;
    if(num[index]<=target){
        take=1+solve(index,num,target-num[index]);
    }
    int not_take=solve(index-1,num,target);

    return dp[index][target]=min(take,not_take);
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n=num.size();
    dp.assign(n,vector<int>(x+1,-1));
    int ans=solve(n-1,num,x);

    if(ans>=1e9){
        return -1;
    }
    return ans;
}


//Tabulation
#include <bits/stdc++.h> 

int solve(vector<int>& num,int x){
    vector<int> dp(x+1,INT_MAX);
    dp[0]=0;

    for(int i=1;i<=x;i++){
        //trying to solve for every target value from 1 to target
        for(int j=0;j<num.size();j++){
            if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX){
                dp[i]=min(dp[i],1+dp[i-num[j]]);
            }
        }
    }

    if(dp[x]==INT_MAX){
        return -1;
    }
    return dp[x];
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    return solve(num,x);
}