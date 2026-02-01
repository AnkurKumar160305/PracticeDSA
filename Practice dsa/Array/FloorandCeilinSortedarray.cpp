#include<bits/stdc++.h>
using namespace std;

pair<int,int> getFloorAndCeil(int arr[],int n,int x){
    int floor=-1,ceil=-1;
    int left=0,right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==x){
            floor=arr[mid];
            ceil=arr[mid];
            return {floor,ceil};
        }else if(arr[mid]<x){
            floor=arr[mid];
            left=mid+1;
        }else{
            ceil=arr[mid];
            right=mid-1;
        }
    }
    return {floor,ceil};
}

int main() {
    int arr[] = {3, 4, 4, 7, 8, 10};
    int n = 6, x = 5;
    pair<int, int> ans = getFloorAndCeil(arr, n, x);
    cout << "The floor and ceil are: " << ans.first << " " << ans.second << endl;
    return 0;
}