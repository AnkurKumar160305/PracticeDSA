#include<bits/stdc++.h>
using namespace std;


bool canPlace(vector<int>& stalls,int cows,int dist){
    int n=stalls.size();
    int count=1;
    int pos=stalls[0];
    for(int i=1;i<n;i++){
        int d=stalls[i]-pos;
        if(d>=dist){
            count++;
            pos=stalls[i];
        }
        if(count==cows){
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int>& stalls,int cows){
    sort(stalls.begin(),stalls.end());
    int left=1;
    int right=stalls.back()-stalls.front();
    int ans=0;

    while(left<=right){
        int mid=left+(right-left)/2;
        if(canPlace(stalls,cows,mid)){
            ans=mid;
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return ans;
}



int main() {
    // Input stalls
    vector<int> stalls = {1, 2, 8, 4, 9};
    // Number of cows
    int cows = 3;
    // Print result
    cout << aggressiveCows(stalls, cows) << endl;
    return 0;
}