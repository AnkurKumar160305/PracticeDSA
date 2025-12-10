class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int> ans;
        int left1=0,left2=0;
        while(left1<m && left2<n){
            if(nums1[left1]<=nums2[left2]){
                ans.push_back(nums1[left1]);
                left1++;
            }else{
                ans.push_back(nums2[left2]);
                left2++;
            }
        }

        while(left1<m){
            ans.push_back(nums1[left1]);
            left1++;
        }
        while(left2<n){
            ans.push_back(nums2[left2]);
            left2++;
        }

        if((n+m)%2==0){
            return (ans[(n+m)/2]+ans[((n+m)/2)-1])/2.0;
        }
        return ans[(n+m)/2];
        
    }
};

//Optimal approach