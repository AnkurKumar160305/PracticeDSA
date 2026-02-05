class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        
        int sum=0,mini=INT_MAX;
        int left=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            while(sum>x){
                mini=min(mini,i-left+1);
                sum-=arr[left];
                left++;
            }
        }
        return (mini==INT_MAX)? 0:mini;
    }
};