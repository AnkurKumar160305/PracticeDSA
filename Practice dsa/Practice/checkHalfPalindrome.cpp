#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s,int left,int right){
    if(left>=right){
        return true;
    }
    if(s[left]!=s[right]){
        return false;
    }
    return isPalindrome(s,left+1,right-1);
}
int main(){
    string s="abba";
    int n=s.size();
    int len=0;
    if(n%2==0){
        len=n/2;
    }else{
        len=(n/2)+1;
    }

    if(isPalindrome(s,0,len-1)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}