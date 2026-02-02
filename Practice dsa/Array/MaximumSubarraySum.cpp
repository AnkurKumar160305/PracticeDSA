#include<bits/stdc++.h>
using namespace std;


// int MaximumSubarraySum(vector<int> &arr,int k){
//     int n=arr.size();
//     int maxi=0;
//     for(int i=0;i<n;i++){
//         int sum=0;
//         for(int j=i;j<n;j++){
//             if(j-i+1<=k){
//                 sum+=arr[j];
//             }
//         }
//         maxi=max(maxi,sum);
//     }
//     return maxi;
// }
int MaximumSubarraySum(vector<int> &arr,int k){
    int n=arr.size();
    if (n < k) return -1;

    int window=0;
    for(int i=0;i<k;i++){
        window+=arr[i];
    }
    int maxi=window;
    for(int i=k;i<n;i++){
        window+=arr[i]-arr[i-k];
        maxi=max(maxi,window);
    }
    return maxi;
}


int main(){
    vector<int> arr={1,3,9,10,2,6,7,8};
    int k=3;
    cout<<MaximumSubarraySum(arr,k);
}
