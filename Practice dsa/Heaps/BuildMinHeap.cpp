#include <bits/stdc++.h> 
void heapify(vector<int>& arr,int n,int i){
    //heapify for max heap moves the element at index i to its correct position in the heap
    //we do not process leaf nodes because they are already in correct position leaf node ranges from index n/2+1 to n where n is the size of the heap/heap array
    //So we will only process non-leaf nodes which ranges from index 1 to n/2

    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[smallest]>arr[left]){
        smallest=left;
    }
    if(right<n && arr[smallest]>arr[right]){
        smallest=right;
    }
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    return arr;
}
