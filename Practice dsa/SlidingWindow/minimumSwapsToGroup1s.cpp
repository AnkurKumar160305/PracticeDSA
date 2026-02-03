class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n=arr.size();
        int ones=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                ones++;
            }
        }
        if(ones==0){
            return -1;
        }
        int bad=0;
        for(int i=0;i<ones;i++){
            if(arr[i]==0){
                bad++;
            }
        }
        int mini=bad;
        int i=0,j=ones;
        while(j<n){
            if(arr[i]==0){
                bad--;
            }
            if(arr[j]==0){
                bad++;
            }
            mini=min(mini,bad);
            i++;
            j++;
        }
        return mini;
    }
};