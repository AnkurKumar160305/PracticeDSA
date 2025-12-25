#include<bits/stdc++.h>
using namespace std;

// bool isSorted(int arr[],int size){
//     if(size==0 || size==1){
//         return true;
//     }

//     if(arr[0]>arr[1]){
//         return false;
//     }else{
//         return isSorted(arr+1,size-1);
//     }
// }

// int Sum(int arr[],int size){
//     if(size==0){
//         return 0;
//     }
//     if(size==1){
//         return arr[0];
//     }
//     return arr[0]+Sum(arr+1,size-1);
// }

// bool linearSearch(int arr[],int size,int target){
//     if(size==0){
//         return false;
//     }
//     if(arr[0]==target){
//         return true;
//     }else{
//         return linearSearch(arr+1,size-1,target);
//     }
// }

bool binarySearch(int arr[],int left,int right,int target){
    if(left>right){
        return false;
    }
    int mid=left+(right-left)/2;
    if(arr[mid]==target){
        return true;
    }

    if(arr[mid]<target){
        return binarySearch(arr,mid+1,right,target);
    }else{
        return binarySearch(arr,left,mid-1,target);
    }
}
int main(){
    int arr[5]={1,2,3,4,5};
    int size=5;

    // bool ans=isSorted(arr,size);
    // if(ans){
    //     cout<<"Array is sorted";
    // }else{
    //     cout<<"Array is not sorted";
    // }


    // cout<<"Sum of array  is: "<<Sum(arr,size);

    int target=9;
    // bool ans=linearSearch(arr,size,target);
    bool ans=binarySearch(arr,0,size-1,target);
    if(ans){
        cout<<"Target found"<<endl;
    }else{
        cout<<"Target not found"<<endl;
    }
    return 0;
}