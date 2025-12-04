#include <bits/stdc++.h>
using namespace std;


vector<int> findMissingRepeatingNumbers(vector<int>& nums){
    long long n=nums.size();
    long long SN=n*(n+1)/2;
    long long S2N=n*(n+1)*(2*n+1)/6;


    long long S=0,S2=0;
    for(int i=0;i<n;i++){
        S+=nums[i];
        S2+=((long long)nums[i]*(long long)nums[i]);
    }

    long long val1 = S - SN;        // repeating - missing
    long long val2 = S2 - S2N;      // repeating^2 - missing^2
    val2 = val2 / val1;             // repeating + missing

    long long repeating = (val1 + val2) / 2;
    long long missing = repeating - val1;


    return {(int)repeating,(int)missing};
}


//Optimal 2 using XOR
vector<int> findMissingRepeatingNumbers(vector<int>& nums){
    long long n=nums.size();
    long long xr=0;

    for(int i=0;i<n;i++){
        xr^=nums[i];
        xr^=(i+1);
    }


    int bitNo=0;
    while(1){
        if((xr & (1<<bitNo))!=0){
            break;
        }
        bitNo++;
    }
    //OR
    // int number=xr & ~(xr-1); //rightmost set bit

    
    long long zero=0,one=0;
    for(int i=0;i<n;i++){
        if((nums[i] & (1<<bitNo))!=0){
            one^=nums[i];
        }else{
            zero^=nums[i];
        }
    }
    for(int i=1;i<=n;i++){
        if((i & (1<<bitNo))!=0){
            one^=i;
        }else{
            zero^=i;
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        if(nums[i]==one){
            cnt++;
        }
    }
    if(cnt==2){
        return {(int)one,(int)zero};
    }
    return {(int)zero,(int)one};
}


int main() {
    vector<int> nums = {3, 1, 2, 5, 4, 6, 7, 5};

    vector<int> result = findMissingRepeatingNumbers(nums);
    
    // Print the repeating and missing numbers found
    cout << "The repeating and missing numbers are: {" << result[0] << ", " << result[1] << "}\n";
    
    return 0;
}