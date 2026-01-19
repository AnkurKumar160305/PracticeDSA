4223
11
2

int countDigits(int n){
    if(n==0){
        return 0;
    }
    int cnt=0;
    while(n!=0){
        n=n/10;
        cnt++;
    }
    return cnt;
}
int singleDigit(int n){
    if(countDigits(n)==1){
        return n;
    }
    int sum=0;
    while(n!=0){
        int d=n%10;
        n=n/10;
        sum+=d;
    }
    return singleDigit(sum);
}
gyugksenjksegsjbkswwervrwev