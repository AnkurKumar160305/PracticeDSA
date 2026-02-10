class Solution {
public:
    int accountBalanceAfterPurchase(int pA) {
        int mini=INT_MAX;
        int index=-1;
        for(int i=0;i<=100;i+=10){
            int dist=abs(pA-i);
            if(dist<mini || (dist==mini && i>index)){
                mini=dist;
                index=i;
            }
        }
        return 100-index;
    }
};