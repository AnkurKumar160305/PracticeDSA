class Solution {
    bool countDays(vector<int>& bloomDay,int m,int k,int mid){
        int cntFlower=0,cntBoq=0;
        for(int b:bloomDay){
            if(b<=mid){
                cntFlower++;
                if(cntFlower==k){
                    cntBoq++;
                    cntFlower=0;
                }
            }else{
                cntFlower=0;
            }
        }
        return cntBoq>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(1LL*m*k>n){
            return -1;
        }

        int low=1;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(maxi<bloomDay[i]){
                maxi=bloomDay[i];
            }
        }
        int ans=-1;
        while(low<=maxi){
            int mid=low+(maxi-low)/2;
            if(countDays(bloomDay,m,k,mid)){
                ans=mid;
                maxi=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;

    }
};