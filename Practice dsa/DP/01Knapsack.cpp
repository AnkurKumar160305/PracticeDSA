//Bounded Knapsack Problem means using same item only once. So, we will decrease the index in case of taking the item.

#include <bits/stdc++.h> 


int solve(vector<int> weight, vector<int> value, int index, int W) 
{
	// Write your code here
	//If only one item left just compare it  with W capacity of bag
	if(index==0){
		if(weight[0]<=W){
			return value[0];
		}
		return 0;
	}

	int include=0;
	if(weight[index]<=W){
		include=value[index]+solve(weight,value,index-1,W-weight[index]);
	}
	int exclude=solve(weight,value,index-1,W);

	return max(include,exclude);

}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	return solve(weight,value,n-1,maxWeight);
}


//Using memoization
#include <bits/stdc++.h> 


int solve(vector<int> weight, vector<int> value, int index, int W,vector<vector<int>>& dp) 
{
	// Write your code here
	//If only one item left just compare it  with W capacity of bag
	if(index==0){
		if(weight[0]<=W){
			return value[0];
		}
		return 0;
	}
	if(dp[index][W]!=-1) return dp[index][W];

	int include=0;
	if(weight[index]<=W){
		include=value[index]+solve(weight,value,index-1,W-weight[index],dp);
	}
	int exclude=solve(weight,value,index-1,W,dp);

	dp[index][W]=max(include,exclude);

	return dp[index][W];

}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return solve(weight,value,n-1,maxWeight,dp);
}


//Tabulation
#include <bits/stdc++.h> 


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	int W=maxWeight;
	vector<vector<int>> dp(n,vector<int>(W+1,0));
	
	// dp[index][w] = maximum value we can get using items from 0 to index with capacity w
	// Base case: only item 0 is available
	// we treated item = 0 seperately because, there is no previous item to use in the recurrence.
	for(int w=weight[0];w<=W;w++){
		dp[0][w]=value[0];
	}

	for(int index=1;index<n;index++){
		for(int w=0;w<=W;w++){
			int include=0;
			if(weight[index]<=w){
				include=value[index]+dp[index-1][w-weight[index]];
			}
			int exclude=dp[index-1][w];

			dp[index][w]=max(include,exclude);
		}
	}


	return dp[n-1][W];
}

//Space Optimization
#include <bits/stdc++.h> 


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	int W=maxWeight;
	vector<int> prev(W+1,0);
	vector<int> curr(W+1,0);
	
	// dp[index][w] = maximum value we can get using items from 0 to index with capacity w
	// Base case: only item 0 is available
	// we treated item = 0 seperately because, there is no previous item to use in the recurrence.
	for(int w=weight[0];w<=W;w++){
		prev[w]=value[0];
	}

	for(int index=1;index<n;index++){
		for(int w=0;w<=W;w++){
			int include=0;
			if(weight[index]<=w){
				include=value[index]+prev[w-weight[index]];
			}
			int exclude=prev[w];

			curr[w]=max(include,exclude);
		}
		prev=curr;
	}


	return prev[W];
}


//Space Optimization with 1D array
#include <bits/stdc++.h> 


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	int W=maxWeight;
	vector<int> curr(W+1,0);
	
	// Base case: only item 0 is available
	// we treated item = 0 seperately because, there is no previous item to use in the recurrence.
	for(int w=weight[0];w<=W;w++){
		curr[w]=value[0];
	}

	for(int index=1;index<n;index++){
		for(int w=W;w>=0;w--){
			int include=0;
			if(weight[index]<=w){
				include=value[index]+curr[w-weight[index]];
			}
			int exclude=curr[w];

			curr[w]=max(include,exclude);
		}
	}


	return curr[W];
}


//Unbounded Knapsack Problem means using same item multiple times. So, we can use the same item again and again. So, we wil not decrease the index in case of taking the item...
class Solution {
    vector<vector<int>> dp;
    int solve(int index,vector<int>& val, vector<int>& wt, int W){
        if(index==0){
            return (W/wt[0])*val[0];
        }
        if(dp[index][W]!=-1) return dp[index][W];
        
        int take=0;
        if(wt[index]<=W){
            take=val[index]+solve(index,val,wt,W-wt[index]);
        }
        int not_take=solve(index-1,val,wt,W);
        
        return dp[index][W]=max(take,not_take);
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=wt.size();
        dp.assign(n,vector<int>(capacity+1,-1));
        return solve(n-1,val,wt,capacity);
        
    }
};