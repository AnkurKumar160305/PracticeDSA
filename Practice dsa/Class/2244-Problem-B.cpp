// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        long long presum=0;
        long long sum=0;
        bool ok=true;
        for(int i=1;i<=n-1;i++){
            sum+=arr[i-1];
            presum+=i;
            if(sum<presum){
                ok=false;
                break;
            }
        }
        if(ok==true){
            sum+=arr[n-1];
            presum+=n;
            if(sum<presum){
                ok=false;
            }
        }
        
        if(ok==false){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    
    
    return 0;
}