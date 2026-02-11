#include<bits/stdc++.h>
using namespace std;


int main(){
    string s="abcba";
    int n=s.size();
    int count=0;
    for(int i=0;i<=n-3;i++){
        char c1=s[i];
        char c2=s[i+1];
        char c3=s[i+2];
        if(c1!=c2 && c2!=c3 && c1!=c3){
            count++;
        }
    }
    cout<<count;
}