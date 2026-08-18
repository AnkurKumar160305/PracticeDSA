#include<bits/stdc++.h>

int solve(int n, vector<int>& days, vector<int>& cost,int index){
    if(index>=n){
        return 0;
    }
    //1 DAY PASS
    int op1=cost[0]+solve(n,days,cost,index+1);

    //2 DAy PASS
    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);
    int op2=cost[1]+solve(n,days,cost,i);

    //3 DAY PASS
    for(i=index;i<n && days[i]<days[index]+30;i++);
    int op3=cost[2]+solve(n,days,cost,i);

    return min({op1,op2,op3});

}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    return solve(n,days,cost,0);
}

//using memoization
#include<bits/stdc++.h>

int solve(int n, vector<int>& days, vector<int>& cost,int index,vector<int>& dp){
    if(index>=n){
        return 0;
    }
    if(dp[index]!=-1) return dp[index];
    //1 DAY PASS
    int op1=cost[0]+solve(n,days,cost,index+1,dp);

    //2 DAy PASS
    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);
    int op2=cost[1]+solve(n,days,cost,i,dp);

    //3 DAY PASS
    for(i=index;i<n && days[i]<days[index]+30;i++);
    int op3=cost[2]+solve(n,days,cost,i,dp);

    return dp[n]=min({op1,op2,op3});

}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    vector<int> dp(n+1,-1);
    return solve(n,days,cost,0,dp);
}

//using tabulation
#include<bits/stdc++.h>

int solve(int n, vector<int>& days, vector<int>& cost){
    vector<int> dp(n+1,INT_MAX);
    dp[n]=0;

    for(int k=n-1;k>=0;k--){
        //1 DAY PASS
        int op1=cost[0]+dp[k+1];

        //2 DAy PASS
        int i;
        for(i=k;i<n && days[i]<days[k]+7;i++);
        int op2=cost[1]+dp[i];

        //3 DAY PASS
        for(i=k;i<n && days[i]<days[k]+30;i++);
        int op3=cost[2]+dp[i];

        dp[k]=min({op1,op2,op3});
    }
    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    return solve(n,days,cost);
}



//space optimization

#include<bits/stdc++.h>
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    int ans=0;
    queue<pair<int,int>> week;
    queue<pair<int,int>> month;

    for(int day:days){


        //step1 : remove expired days
        while(!month.empty() && month.front().first+30<=day){
            month.pop();
        }
        while(!week.empty() && week.front().first+7<=day){
            week.pop();
        }

        //step2 : add cost for current day
        week.push({day,ans+cost[1]});
        month.push({day,ans+cost[2]});

        //step3: ans update
        ans=min({ans+cost[0],
        week.front().second,month.front().second});
    }

    return ans;
}