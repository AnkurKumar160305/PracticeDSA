#include<bits/stdc++.h>
using namespace std;


void printOdd(int n){
    if(n<=0){
        return;
    }
    if(n%2!=0){
        cout<<n<<" ";
        printOdd(n-2);
    }else{
        printOdd(n-1);
    }
}

int main(){
    int n=5;
    printOdd(n);
}