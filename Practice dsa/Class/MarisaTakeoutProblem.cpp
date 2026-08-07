// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int cnt0=0;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                cnt0++;
            }else if(arr[i]==1){
                cnt1++;
            }else{
                cnt2++;
            }
        }
        int total = cnt0;
        int best = 0;

        for (int x = 0; x <= min(cnt1, cnt2); x++) {
            int cur = x;
            cur += (cnt1 - x) / 3;
            cur += (cnt2 - x) / 3;
            best = max(best, cur);
        }

        cout << total + best << endl;
        
        cout<<"ans is: "<<total<<endl;
    }
    
    return 0;
}