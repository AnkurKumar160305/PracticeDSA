class Solution {
    bool isValid(vector<int>& weights,int days,int mid){
        int load=0,cntDays=1;
        for(int i:weights){
            if(load+i<=mid){
                load+=i;
            }else{
                cntDays++;
                load=i;
                if(cntDays>days){
                    return false;
                }
            }
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(weights,days,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;

    }
};