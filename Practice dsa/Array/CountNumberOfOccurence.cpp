#include<bits/stdc++.h>
using namespace std;

int findUpperbound(vector<int>& arr,int target){
    int low=0,high=arr.size()-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            ans=mid;
            low=mid+1;
        }else if(arr[mid]<target){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}
int findLowerbound(vector<int>& arr,int target){
    int low=0,high=arr.size()-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            ans=mid;
            high=mid-1;
        }else if(arr[mid]<target){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}


int main(){
    vector<int> arr={1,2,2,2,3,4,5};
    int target=2;
    int lb = findLowerbound(arr, target);
    if (lb == -1) {
        cout << 0;
        return 0;
    }

    int ub = findUpperbound(arr, target);
    cout << ub - lb + 1;
}