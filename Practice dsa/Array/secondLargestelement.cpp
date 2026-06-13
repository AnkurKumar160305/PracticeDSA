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

int secondLargest(vector<int>& arr) {
    int largest = INT_MIN;
    int second = INT_MIN;

    for (int x : arr) {
        if (x > largest) {
            second = largest;
            largest = x;
        }
        else if (x > second && x != largest) {
            second = x;
        }
    }

    return (second == INT_MIN) ? -1 : second;
}

int main(){
    vector<int> arr={1, 5, 4, 3, 7, 8, 2, 8};
    int ans=secondLargest(arr);
    cout<<ans;
}