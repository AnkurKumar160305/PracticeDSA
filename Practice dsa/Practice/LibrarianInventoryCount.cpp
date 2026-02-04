int findUpperbound(vector<int>& arr,int target){
    int l=0,r=arr.size()-1;
    int ans=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==target){
            ans=mid;
            l=mid+1;
        }else if(arr[mid]<target){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return ans;
}

int findLowerbound(vector<int>& arr,int target){
    int l=0,r=arr.size()-1;
    int ans=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==target){
            ans=mid;
            r=mid-1;
        }else if(arr[mid]<target){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return ans;
}

int countOccurrences(vector<int>& arr, int target) { 
    int l=findLowerbound(arr,target);
    if(l==-1){
        return 0;
    }
    return findUpperbound(arr,target)-l+1;
}

