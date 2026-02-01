class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)){
            return false;
        };
        int rev=0;
        while(x>rev){
            int d=x%10;
            x/=10;
            rev=rev*10+d;
        }
        return (x == rev || x == rev / 10);
    }
};