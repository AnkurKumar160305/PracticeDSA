class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int temp=numBottles;
        int sum=temp;

        while(temp>=numExchange){
            int filled=temp/numExchange;
            int emp=temp%numExchange;
            sum+=filled;
            temp=filled+emp;
        }

        return sum;
    }
};