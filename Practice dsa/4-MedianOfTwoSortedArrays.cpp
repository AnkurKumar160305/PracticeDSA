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
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        int i=0,j=0;
        int ind2=n/2;
        int ind1=ind2-1;
        int cnt=0;
        int ind1el=-1,ind2el=-1;

        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(cnt==ind1) ind1el=nums1[i];
                if(cnt==ind2) ind2el=nums1[i];
                cnt++;
                i++;
            }else{
                if(cnt==ind1) ind1el=nums2[j];
                if(cnt==ind2) ind2el=nums2[j];
                cnt++;
                j++;
            }
        }

        while(i<n1){
            if(cnt==ind1) ind1el=nums1[i];
            if(cnt==ind2) ind2el=nums1[i];
            cnt++;
            i++;
        }
        while(j<n2){
            if(cnt==ind1) ind1el=nums2[j];
            if(cnt==ind2) ind2el=nums2[j];
            cnt++;
            j++;
        }

        if(n%2==1){
            return ind2el;
        }

        return (double)((double)ind1el+(double)ind2el)/2.0;
        
    }
};


//Optimal
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1=a.size();
        int n2=b.size();
        if(n1>n2){
            return findMedianSortedArrays(b,a);
        }
        int n=(n1+n2);
        int left=(n1+n2+1)/2;
        int low=0,high=n1;
        while(low<=high){
            int mid1=low+(high-low)/2;
            int mid2=left-mid1;
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            if(mid1<n1) r1=a[mid1];
            if(mid2<n2) r2=b[mid2];
            if(mid1-1>=0) l1=a[mid1-1];
            if(mid2-1>=0) l2=b[mid2-1];
            if(l1<=r2 && l2<=r1){
                if(n%2==1){
                    return max(l1,l2);
                }else{
                    return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
                }
            }else if(l1>r2){
                high=mid1-1;
            }else{
                low=mid1+1;
            }
        }

        return 0;
        
    }
};