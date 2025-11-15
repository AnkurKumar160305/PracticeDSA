#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={1,5,4,3,7,8,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    InsertionSort(arr,n);
}