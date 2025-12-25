#include<bits/stdc++.h>
using namespace std;


void merge(int *arr,int s,int e){
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;

    int *first=new int[len1];
    int *second=new int[len2];

    //copy values
    int mainArrayindex=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[mainArrayindex++];
    }
    mainArrayindex=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[mainArrayindex++];
    }

    //merge two arrays
    int index1=0;
    int index2=0;
    mainArrayindex=s;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[mainArrayindex++]=first[index1++];
        }else{
            arr[mainArrayindex++]=second[index2++];
        }
    }
    while(index1<len1){
        arr[mainArrayindex++]=first[index1++];
    }
    while(index2<len2){
        arr[mainArrayindex++]=second[index2++];
    }
    delete []first;
    delete []second;
}

void mergeSort(int *arr,int s,int e){
    if(s>=e){
        return;
    }
    int mid=s+(e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}

//Inversion count
// i<j and arr[i]>arr[j]
// Inversion count tells how far the array is from being sorted.
// If inversion count = 0 → array is already sorted.
// Maximum inversions → array is sorted in reverse order.

int main(){

    int arr[5]={2,5,1,3,4};
    mergeSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


// Merge function modified to count inversions
long long merge(int *arr, int s, int e) {
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int mainIndex = s;
    for (int i = 0; i < len1; i++) first[i] = arr[mainIndex++];
    mainIndex = mid + 1;
    for (int i = 0; i < len2; i++) second[i] = arr[mainIndex++];

    // merge two arrays & count inversions
    int i = 0, j = 0;
    mainIndex = s;
    long long invCount = 0;

    while (i < len1 && j < len2) {
        if (first[i] <= second[j]) {
            arr[mainIndex++] = first[i++];
        } else {
            arr[mainIndex++] = second[j++];
            invCount += (len1 - i); // all remaining in left array are inversions
        }
    }

    while (i < len1) arr[mainIndex++] = first[i++];
    while (j < len2) arr[mainIndex++] = second[j++];

    delete[] first;
    delete[] second;

    return invCount;
}

// MergeSort function modified to return inversion count
long long mergeSort(int *arr, int s, int e) {
    if (s >= e) return 0;

    int mid = s + (e - s) / 2;
    long long leftInv = mergeSort(arr, s, mid);
    long long rightInv = mergeSort(arr, mid + 1, e);
    long long mergeInv = merge(arr, s, e);

    return leftInv + rightInv + mergeInv;
}

int main() {
    int arr[5] = {2, 5, 1, 3, 4};
    long long invCount = mergeSort(arr, 0, 4);

    cout << "Sorted Array: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "Inversion Count: " << invCount << endl;

    return 0;
}
