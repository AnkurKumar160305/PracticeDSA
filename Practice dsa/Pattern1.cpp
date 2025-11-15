#include<bits/stdc++.h>
using namespace std;


// int main(){
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         for(int j=n;j>i;j--){
//             cout<<n-j+1<<" ";
//         }
//         cout<<endl;
//     }
// }

// int main(){
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         for(int j=n;j>i;j--){
//             cout<<n-j+1<<" ";
//         }
//         cout<<endl;
//     }
// }

// int main(){
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n-i-1;j++){
//             cout<<" ";
//         }
//         for(int j=0;j<2*i+1;j++){
//             cout<<"*";
//         }
//         for(int j=0;j<n-i-1;j++){
//             cout<<" ";
//         }
//         cout<<endl;
//     }
// }

// int main(){
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<i;j++){
//             cout<<" ";
//         }
//         for(int j=0;j<2*(n-i)-1;j++){
//             cout<<"*";
//         }
//         for(int j=0;j<i;j++){
//             cout<<" ";
//         }
//         cout<<endl;
//     }
// }


// int main(){
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n-i-1;j++){
//             cout<<" ";
//         }
//         for(int j=0;j<2*i+1;j++){
//             cout<<"*";
//         }
//         for(int j=0;j<n-i-1;j++){
//             cout<<" ";
//         }
//         cout<<endl;
//     }
    
//     for(int i=0;i<n;i++){
//         for(int j=0;j<i;j++){
//             cout<<" ";
//         }
//         for(int j=0;j<2*(n-i)-1;j++){
//             cout<<"*";
//         }
//         for(int j=0;j<i;j++){
//             cout<<" ";
//         }
//         cout<<endl;
//     }
// }


// int main(){
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<=i;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }

//     for(int i=0;i<n;i++){
//         for(int j=0;j<n-i-1;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }

// int main(){
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<=i;j++){
//             if((i+j)%2==0){
//                 cout<<"1 ";
//             }
//             else{
//                 cout<<"0 ";
//             }
//         }
//         cout<<endl;
//     }
// }


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){

        for(int j=0;j<=i;j++){
            cout<<j+1<<" ";
        }

        for(int j=0;j<2*(n-i-2);j++){
            cout<<"  ";
        }

        for(int j=i;j>=0;j--){
            cout<<j+1<<" ";
        }

        cout<<endl;
    }

}
