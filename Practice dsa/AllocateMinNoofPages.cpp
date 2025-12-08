#include<bits/stdc++.h>
using namespace std;


int countStudents(vector<int>& arr,int mid){
    int count=1;
    int pages=0;
    for(int i=0;i<arr.size();i++){
        if(pages+arr[i]<=mid){
            pages+=arr[i];
        }else{
            count++;
            pages=arr[i];
        }
    }
    return count;
}

int findPages(vector<int>& arr,int n,int m){
    if (m > n) return -1;

    int left=*max_element(arr.begin(),arr.end());
    int right=accumulate(arr.begin(),arr.end(),0);

    while(left<=right){
        int mid=left+(right-left)/2;
        int students=countStudents(arr,mid);
        if(students>m){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return left;
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}