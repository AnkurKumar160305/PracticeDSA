// Minimum swaps and K together
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        
        int good=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                good++;
            }
        }
        
        int bad = 0;
        for (int i = 0; i < good; i++) {
            if (arr[i] > k) {
                bad++;
            }
        }
        
        int mini = bad;
        int i = 0, j = good;
        while (j < n) {
            // remove left element
            if (arr[i] > k) {
                bad--;
            }

            // add right element
            if (arr[j] > k) {
                bad++;
            }

            mini = min(mini, bad);
            i++;
            j++;
        }

        return mini;
    }
};
