#include<bits/stdc++.h>
using namespace std;

// void Reverse(string& s,int left,int right){
//     if(left>=right){
//         return;
//     }
//     swap(s[left],s[right]);
//     Reverse(s,left+1,right-1);
// }

//OR

// void Reverse(string& s,int left,int size){
//     if(left>=size-left-1){
//         return;
//     }
//     swap(s[left],s[size-left-1]);
//     Reverse(s,left+1,size);
// }

// bool isPalindrome(string s,int left,int right){
//     if(left>=right){
//         return true;
//     }
//     if(s[left]!=s[right]){
//         return false;
//     }
//     return isPalindrome(s,left+1,right-1);
// }


// int Power(int a,int b){
//     if(b==0){
//         return 1;
//     }
//     if(b==1){
//         return a;
//     }
//     int ans=Power(a,b/2);

//     //if b is even
//     if(b%2==0){
//         return ans*ans;

//     }else{
//         //if b is odd
//         return a*ans*ans;
//     }
// }


//Bubble Sort - in sequence positioning each element to its right place
void sortArray(int arr[],int n){
    if(n==0 || n==1){
        return;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    sortArray(arr,n-1);
}
int main(){
    // string s="aba";
    // Reverse(s,0,s.size());
    // cout<<s<<endl;

    // bool ans=isPalindrome(s,0,s.size()-1);
    // if(ans){
    //     cout<<"String is Palindrome";
    // }else{
    //     cout<<"String is not Palindrome";
    // }

    // int a=3,b=5;
    // cout<<Power(a,b);

    int arr[5]={2,5,1,3,4};
    sortArray(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}