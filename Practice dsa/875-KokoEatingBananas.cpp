//For Small Inputs Only
class Solution {
    int search(vector<int>& piles,int k){
        int n=piles.size();
        int ans=0;
        for(int j=0;j<n;j++){
            ans+=ceil((double)piles[j]/k);
        }
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(piles[i]>maxi){
                maxi=piles[i];
            }
        }
        int ans=maxi;
        for(int k=1;k<=maxi;k++){
            if(search(piles,k)<=h){
                ans=k;
                break;
            }
        }
        return ans;

    }
};


//For large Inputs
class Solution {
    long long search(vector<int>& piles,long long k){
        int n=piles.size();
        long long ans=0;
        for(int j=0;j<n;j++){
            ans += (piles[j] + k - 1) / k; // integer math equivalent to ceil(piles[j]/k)
            // ans+=ceil((double)piles[j]/k);
        }
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long n=piles.size();
        long long maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(piles[i]>maxi){
                maxi=piles[i];
            }
        }
        long long ans=maxi;
        long long left=1,right=maxi;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(search(piles,mid)<=h){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return (int)ans;

    }
};