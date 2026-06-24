class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;

        int i=0,j=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            long long prod1=1,prod2=1;
            int j=0,k=nums.size()-1;
            while(j<i){
                prod1*=nums[j];
                j++;
            }
            while(k>i){
                prod2*=nums[k];
                k--;
            }
            ans.push_back(prod1*prod2);
        }


        return ans;
    }
};


//Optimal
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        int prefix = 1;
        for(int i = 0; i < n; i++) {
            ans[i]=prefix;
            prefix*=nums[i];
        }
        int suffix = 1;
        for(int i = n-1; i >=0; i--) {
            ans[i]*=suffix;
            suffix*=nums[i];
        }
        return ans;
    }
};