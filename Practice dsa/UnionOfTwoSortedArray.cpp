//Correct MERGE of two sorted arrays (without removing duplicates)
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n=nums1.size(),m=nums2.size();

        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            ans.push_back(nums2[j]);
            j++;
        }

        return ans;
    }
};

// REAL union (unique elements)
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n=nums1.size(),m=nums2.size();

        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                if(ans.empty() || ans.back()!=nums1[i]){
                    ans.push_back(nums1[i]);
                }
                i++;
            }else if(nums2[j]<nums1[i]){
                if(ans.empty() || ans.back()!=nums2[j]){
                    ans.push_back(nums2[j]);
                }
                j++;
            }else{
                if(ans.empty() || ans.back()!=nums1[i]){
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        while(i<n){
            if(ans.empty() || ans.back()!=nums1[i]){
                ans.push_back(nums1[i]);
            }
            i++;
        }
        while(j<m){
            if(ans.empty() || ans.back()!=nums2[j]){
                ans.push_back(nums2[j]);
            }
            j++;
        }

        return ans;
    }
};