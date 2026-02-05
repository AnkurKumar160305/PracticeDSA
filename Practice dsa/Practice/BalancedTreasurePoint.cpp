int balancedTreasurePoint(vector<int>& arr) {
    int totalsum=0;
    for(int i=0;i<arr.size();i++){
        totalsum+=arr[i];
    }
    int leftsum=0;
    for(int i=0;i<arr.size();i++){
        if(leftsum==totalsum-leftsum-arr[i]){
            return i;
        }
        leftsum+=arr[i];
    }
    return -1;
}