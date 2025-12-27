class Solution {
    long long MOD = 1000000007;
    long long Power(long long x,long long pos){
        if(pos==0){
            return 1;
        }
        long long ans=Power(x,pos/2);
        if(pos%2==0){
            return (ans*ans)%MOD;
        }else{
            return (((ans*ans)%MOD)*x)%MOD;
        }
    }
public:
    int countGoodNumbers(long long n) {
        long long evenPos=(n+1)/2;
        long long oddPos=(n)/2;

        long long ans=(Power(5,evenPos)*Power(4,oddPos))%MOD;

        return (int)ans;
    }
};