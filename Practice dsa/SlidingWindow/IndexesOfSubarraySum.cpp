class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int i=0,j=0;
        long long curr=0;
        while(j<arr.size()){
            curr+=arr[j];
            while(curr>target && i<=j){
                curr=curr-arr[i];
                i++;
            }
            if(curr==target){
                return {i+1,j+1};
            }
            j++;
        }
        return {-1};
    }
};