#include<bits/stdc++.h>
using namespace std;


int countSubarrays(vector<int> &A,int k){
    unordered_map<int,int> m;
    int xoor=0,count=0;
    m[0]=1;

    for(auto num:A){
        xoor^=num;
        int target=xoor^k;
        if(m.find(target)!=m.end()){
            count+=m[target];
        }
        m[xoor]++;
    }
    return count;
}

int main() {
    vector<int> A = {4, 2, 2, 6, 4};
    int k = 6;
    cout << countSubarrays(A, k) << endl;
    return 0;
}