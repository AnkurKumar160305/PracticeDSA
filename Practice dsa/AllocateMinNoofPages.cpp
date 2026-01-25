class Solution {
    int countStudents(vector<int>& arr,int mid,int k){
        int st=1;
        int pages=0;
        
        for(int i=0;i<arr.size();i++){
            if(pages+arr[i]<=mid){
                pages+=arr[i];
            }else{
                st++;
                pages=arr[i];
            }
        }
        return st;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        if(k>n){
            return -1;
        }
        int left=*max_element(arr.begin(),arr.end());
        int right=accumulate(arr.begin(),arr.end(),0);
        int ans=-1;
        
        while(left<=right){
            int mid=left+(right-left)/2;
            int st=countStudents(arr,mid,k);
            
            if(st<=k){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
                
            }
        }
        return ans;
    }
};