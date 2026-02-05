class Solution {
public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int cur_sum = 0;
        int max_sum = INT_MIN;
        
        int size = arr.size();
        for(int i = 0; i <= size-1; i++){
            cur_sum = cur_sum + arr[i];
            if(cur_sum > max_sum){
                max_sum = cur_sum;
            }
            
            if(cur_sum < 0){
                cur_sum = 0;
            }
        }
        return max_sum;
    }
};