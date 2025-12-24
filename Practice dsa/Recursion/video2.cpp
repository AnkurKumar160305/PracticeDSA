#include<bits/stdc++.h>
using namespace std;

// int fibb(int n){
//     //base case
//     if(n<=1){
//         return n;
//     }
//     //recursive relation
//     return fibb(n-1)+fibb(n-2);
// }

// int countDistinctWays(int nStairs) {
//     //  Write your code here.
//     if(nStairs<0){
//         return 0;
//     }
//     if(nStairs==0){
//         return 1;
//     }

//     return countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2);
// }

void sayDigits(int n,string arr[]){
    //base case
    if(n==0){
        return;
    }

    //processing
    int digit=n%10;
    n=n/10;
    
    //recursion
    sayDigits(n,arr);
    
    cout<<arr[digit]<<" ";
}

int main(){
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n;
    cin>>n;
    // cout<<fibb(n);
    cout<<endl<<endl;
    sayDigits(n,arr);
    cout<<endl<<endl;

    return 0;
}