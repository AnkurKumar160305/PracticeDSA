//using recursion
class Solution {
    int solve(int index,int time,vector<int>& s,int n){
        if(index>=n){
            return 0;
        }
        int take=s[index]*time+solve(index+1,time+1,s,n);
        int nottake=solve(index+1,time,s,n);

        return max(take,nottake);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int index=0;
        int time=1;
        int n=satisfaction.size();
        return solve(index,time,satisfaction,n);
    }
};


//using memoization
class Solution {
    int solve(int index,int time,vector<int>& s,int n,vector<vector<int>>& dp){
        if(index>=n){
            return 0;
        }
        if(dp[index][time]!=-1) return dp[index][time];

        int take=s[index]*time+solve(index+1,time+1,s,n,dp);
        int nottake=solve(index+1,time,s,n,dp);

        return dp[index][time]=max(take,nottake);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int index=0;
        int time=1;
        int n=satisfaction.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(index,time,satisfaction,n,dp);
    }
};


//using tabulation
class Solution {
    int solve(vector<int>& s){
        int n=s.size();
        sort(s.begin(),s.end());

        vector<vector<int>> dp(n+1,vector<int>(n+2,0));

        for(int index=n-1;index>=0;index--){
            for(int time=n;time>=1;time--){
                int take=s[index]*time+dp[index+1][time+1];
                int nottake=dp[index+1][time];
                dp[index][time]=max(take,nottake);
            }
        }
        return dp[0][1];
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        return solve(satisfaction);
    }
};


//using space optimization
class Solution {
    int solve(vector<int>& s){
        int n=s.size();
        sort(s.begin(),s.end());

        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);

        for(int index=n-1;index>=0;index--){
            for(int time=index;time>=0;time--){
                int take=s[index]*(time+1)+next[time+1];
                int nottake=next[time];
                curr[time]=max(take,nottake);
            }
            next=curr;
        }
        return next[0];
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        return solve(satisfaction);
    }
};


//using greedy approach
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());

        int sum = 0;
        int ans = 0;

        for (int x : satisfaction) {
            sum += x;

            if (sum > 0) {
                ans += sum;
            } else {
                break;
            }
        }

        return ans;
    }
};