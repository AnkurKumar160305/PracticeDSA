#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int>& arr,int n,int x){
    int left=0,right=n-1;
    int firstIndex=-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==x){
            firstIndex=mid;
            right=mid-1;
        }else if(arr[mid]<x){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return firstIndex;
}
int LastOccurence(vector<int>& arr,int n,int x){
    int left=0,right=n-1;
    int lastIndex=-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==x){
            lastIndex=mid;
            left=mid+1;
        }else if(arr[mid]<x){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return lastIndex;
}

int count(vector<int> &arr,int n,int x){
    int first=firstOccurence(arr,n,x);
    if(first==-1){
        return 0;
    }
    int last=LastOccurence(arr,n,x);
    return last-first+1;
}

int main()
{
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, x = 8;
    int ans = count(arr, n, x);
    cout << "The number of occurrences is: "<< ans << "\n";
    return 0;
}
