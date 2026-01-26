
#include<bits/stdc++.h>
using namespace std;

int maxLen(int &A[],int n){
    unordered_map<int,int> m;
    int sum=0,maxi=0;
    for(int i=0;i<n;i++){
        sum+=A[i];
        if(sum==0){
            maxi=max(maxi,i+1);
        }else if(m.find(sum)!=m.end()){
            maxi=max(maxi,i-m[sum]);
        }else{
            m[sum]=i;
        }
    }
    return maxi;
}

int main() {
  int A[] = {9, -3, 3, -1, 6, -5};
  int n = sizeof(A) / sizeof(A[0]);
  cout << maxLen(A, n) << endl;
  return 0;
}