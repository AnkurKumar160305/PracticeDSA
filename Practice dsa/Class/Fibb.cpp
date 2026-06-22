#include<bits/stdc++.h>
using namespace std;

bool fibb(int n){
    if(n<=1){
        return true;
    }
    return fibb(n-1)+fibb(n-2);
}
vector<vector<int>> solve(vector<vector<int>>& ans,int n){
    for(int i=0;i<n;i++){
        int j=i+1,k=n-1;
        while(j<k){
            if(i+j+k==n && fibb(i)+fibb(j)+fibb(k)==n){
                ans.push_back({i,j,k});
            }
            j++;
            k--;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> ans;
    solve(ans,n);
}