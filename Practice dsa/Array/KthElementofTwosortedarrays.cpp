#include <bits/stdc++.h>
using namespace std;

// int kthElement(vector<int>& a,vector<int>& b,int k){
//     int index=k-1;
//     int n1=a.size(),n2=b.size();
//     int i=0,j=0;
//     int cnt=0;
//     while(i<n1 && j<n2){
//         if(a[i]<b[j]){
//             if(cnt==index){
//                 return a[i];
//             }
//             cnt++;
//             i++;
//         }else{
//             if(cnt==index){
//                 return b[j];
//             }
//             cnt++;
//             j++;
//         }
//     }
    
//     while(i<n1){
//         if(cnt==index){
//             return a[i];
//         }
//         cnt++;
//         i++;
//     }
//     while(j<n2){
//         if(cnt==index){
//             return b[j];
//         }
//         cnt++;
//         j++;
//     }

//     return -1;
// }


//Optimal
int kthElement(vector<int>& a,vector<int>& b,int k){
        int n1=a.size();
        int n2=b.size();
        if(n1>n2){
            return kthElement(b,a,k);
        }
        int n=(n1+n2);
        int left=k;
        int low=max(0,k-n2),high=min(k,n1);
        while(low<=high){
            int mid1=low+(high-low)/2;
            int mid2=left-mid1;

            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            if(mid1<n1) r1=a[mid1];
            if(mid2<n2) r2=b[mid2];
            if(mid1-1>=0) l1=a[mid1-1];
            if(mid2-1>=0) l2=b[mid2-1];

            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }else if(l1>r2){
                high=mid1-1;
            }else{
                low=mid1+1;
            }
        }

        return -1;
}



int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;
    
    cout << "The " << k << "-th element of two sorted arrays is: "<< kthElement(a, b, k) << '\n';

    return 0;
}