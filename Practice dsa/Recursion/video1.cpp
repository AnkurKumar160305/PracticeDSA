#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    //base case
    if(n==0){
        return 1;
    }
    //recursive relation
    return n*factorial(n-1);
}

int power(int n){
    if(n==0){
        return 1;
    }
    return 2*power(n-1);
}

// void print(int n){
//     if(n==0){
//         return;
//     }
//     cout<<n<<" ";
//     //Tail recursion
//     print(n-1);
// }

void print(int n){
    if(n==0){
        return;
    }
    //Head recursion
    print(n-1);
    cout<<n<<" ";
}

int main(){
    int n;
    cin>>n;

    int ans=factorial(n);
    cout<<ans<<endl;

    int pow=power(n);
    cout<<pow<<endl;

    print(n);

    return 0;
}