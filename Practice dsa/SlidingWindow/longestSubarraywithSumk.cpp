//For positive numbers only
#include<bits/stdc++.h>

int longestSubarrayWithSumK(vector<int> arr, long long k) {
        int i=0,j=0;
        long long currSum=0;
        int maxi=0;
        while(j<arr.size()){
            currSum+=arr[j];
            while(currSum>k){
                currSum-=arr[i];
                i++;
            }
            if(currSum==k){
                maxi=max(maxi,j-i+1);
            }
            j++;
        }
    return maxi;
}



// Negative and Positive numbers
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        long long currSum=0;
        unordered_map<int,int> m;
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            currSum+=arr[i];
            if(currSum==k){
                maxi=max(maxi,i+1);
            }
            if(m.find(currSum-k)!=m.end()){
                maxi=max(maxi,i-m[currSum-k]);
            }
            if(m.find(currSum)==m.end()){
                m[currSum]=i;
            }
        }
        return maxi;
    }
};