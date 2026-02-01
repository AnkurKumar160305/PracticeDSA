#include<bits.stdc++.h>
using namespace std;


int findRotations(vector<int>& arr){
    int n=arr.size();
    int low=0,high=n-1;
    while(low<high){
        int mid=low+(high-low)/2;
        
        if (arr[mid] == arr[high]) {
            high--; 
        }else if(arr[mid]>arr[high]){
            low=mid+1;
        }else{
            high=mid;
        }
    }
    return low;
}

int main() {
    vector<int> arr = {4,5,6,7,0,1,2,3};

    int rotations = findRotations(arr);

    cout << rotations << endl;
    return 0;
}