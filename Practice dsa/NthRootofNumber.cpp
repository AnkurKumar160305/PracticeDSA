#include<bits/stdc++.h>
using namespace std;

long long power(long long mid,int n,long long m){
    long long res=1;
    for(int i=1;i<=n;i++){
        if (res > m / mid){
            return m+1;
        }
        res=res*mid;
    }
    return res;
}

int nthRoot(int n, int m) {
    int left=1,right=m;
    while(left<=right){
        long long mid=left+(right-left)/2;
        long long midPower = power(mid, n, m);

        if(midPower==m){
            return mid;
        }else if(midPower < m){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return -1;
}


int main() {
    cout << nthRoot(3,27) << endl;
    return 0;
}