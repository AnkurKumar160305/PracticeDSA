class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,n=nums.size();
        int cnt=0;
        while(i<n){
            if(nums[i]!=0 && cnt<n){
                nums[cnt++]=nums[i];
            }
            i++;
        }
        for(int j=cnt;j<n;j++){
            nums[j]=0;
        }
    }
};
