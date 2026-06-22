class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n>=3){
            return (double)1/2;
        }
        return (double)1/n;
    }
};