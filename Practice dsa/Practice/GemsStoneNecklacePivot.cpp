int findSmallest(vector<int>& gems) { 
    int l=0,r=gems.size()-1;
    while(l<r){
        int mid=l+(r-l)/2;
        if(gems[mid]>gems[r]){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    return gems[l];
}