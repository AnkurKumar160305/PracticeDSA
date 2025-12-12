#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int>& a,vector<int>& b,int k){
    int index=k-1;
    int n1=a.size(),n2=b.size();
    int i=0,j=0;
    int cnt=0;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            if(cnt==index){
                return a[i];
            }
            cnt++;
            i++;
        }else{
            if(cnt==index){
                return b[j];
            }
            cnt++;
            j++;
        }
    }
    
    while(i<n1){
        if(cnt==index){
            return a[i];
        }
        cnt++;
        i++;
    }
    while(j<n2){
        if(cnt==index){
            return b[j];
        }
        cnt++;
        j++;
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