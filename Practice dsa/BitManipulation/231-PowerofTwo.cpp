class Solution {
    // A power of two has exactly one set bit.
    int isPower(long long i,int pow){
        if(pow==0){
            return 1;
        }
        if(pow==1){
            return i;
        }
        long long ans=isPower(i,pow/2);
        if(pow%2==0){
            return ans*ans;
        }else{
            return i*ans*ans;
        }
    }
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;

        int l = 0, r = 30;
        while(l<=r){
            int mid=l+(r-l)/2;
            long long ans=isPower(2,mid);
            if(ans==n){
                return true;
            }else if(ans<n){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return false;

    }
};


class Solution {
    // A power of two has exactly one set bit.
    // n = 8  → 1000
    // n-1 = 7 → 0111
    // AND = 0

public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;

    }
};