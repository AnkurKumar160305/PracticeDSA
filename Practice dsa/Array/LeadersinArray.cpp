#include<bits/stdc++.h>
using namespace std;


// void LeadersinArray(vector<int> &arr,int n){
//     vector<int> ans;
//     for(int i=0;i<n;i++){
//         bool flag=true;
//         for(int j=i+1;j<n;j++){
//             if(arr[i]<arr[j]){
//                 flag=false;
//                 break;
//             }
//         }
//         if(flag){
//             ans.push_back(arr[i]);
//         }
//     }
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<" ";
//     }
// }

void LeadersinArray(vector<int> &arr,int n){
    int maxi=arr[n-1];
    int temp=maxi;
    for(int i=n-2;i>=0;i--){
        if(arr[i]>maxi){
            maxi=arr[i];
            cout<<maxi<<" ";
        }
    }
    cout<<temp<<" ";
}


int main(){
    vector<int> arr={2,7,3,1,5,4,9,6,8};
    int n=arr.size();
    LeadersinArray(arr,n);
    return 0;
}