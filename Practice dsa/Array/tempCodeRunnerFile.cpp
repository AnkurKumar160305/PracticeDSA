#include<bits/stdc++.h>
using namespace std;

int secondLargest(vector<int> &arr){
    set<int> s(arr.begin(), arr.end());

    if(s.size()<2){
        return -1;
    }
    auto it = s.rbegin(); // largest
    ++it;                 // second largest

    return *it;
}
int main(){
    vector<int> arr={1, 5, 4, 3, 7, 8, 2, 8};
    int ans=secondLargest(arr);
    cout<<ans;
}