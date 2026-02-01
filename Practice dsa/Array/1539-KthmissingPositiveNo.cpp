class Solution {
    int missing(vector<int>& arr,int mid){
        return arr[mid]-(mid+1);
    }

public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        if(missing(arr,n-1)<k){
            return arr.back()+(k-missing(arr,n-1));
        }
        int left=0,right=arr.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if (missing(arr,mid) >= k){
                right = mid;
            }else{
                left=mid+1;
            }
        }

        if(left == 0){
            return k;
        }

        int prevMissing = missing(arr, left - 1);
        return arr[left - 1] + (k - prevMissing);
    }
};