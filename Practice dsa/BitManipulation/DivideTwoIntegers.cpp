#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to divide two numbers
    without multiplication and division */
    int divide(int dividend, int divisor) {
        
        // Base case
        if(dividend == divisor) return 1;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;
        
        // Variable to store the sign of result
        bool isPositive = true;
        
        // Updating the sign of quotient
        if(dividend >= 0 && divisor < 0) 
            isPositive = false;
        else if(dividend < 0 && divisor > 0)
            isPositive = false;
            
        // Storing absolute dividend & divisor
        long long n = dividend;
        long long d = divisor;

        n = abs(n);
        d = abs(d);
        
        // Variable to store the answer and sum
        long long ans = 0, sum = 0;
        
        /* Looping while sum added to divisor is
        less than or equal to divisor */
        while(sum + d <= n) {
            
            // Increment the count
           ans++;
           // Update the sum
           sum += d;
        }
        
        // Handling overflowing condition
        if(ans > INT_MAX && isPositive) 
            return INT_MAX;
        if(ans > INT_MAX && !isPositive)
            return INT_MIN;
        
        /* Returning the quotient 
        with proper sign */
        return isPositive ? ans : -1*ans;
    }
};

int main() {
    int dividend = 10, divisor = 3;
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to divide two numbers
    without multiplication and division */
    int ans = sol.divide(dividend, divisor);
    
    cout << "The result of dividing " << dividend << " and " << divisor << " is " << ans;
    
    return 0;
}




//Optimal
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine sign
        bool isPositive = (dividend > 0) == (divisor > 0);

        // Convert to long long and take absolute values
        long long n = llabs(dividend);
        long long d = llabs(divisor);

        long long ans = 0;

        // Main loop
        while (n >= d) {
            long long temp = d;
            long long multiple = 1;

            // Double divisor until it exceeds n
            while ((temp << 1) <= n) {
                temp <<= 1;
                multiple <<= 1;
            }

            // Subtract the largest multiple
            n -= temp;
            ans += multiple;
        }

        return isPositive ? ans : -ans;
    }
};

int main() {
    int dividend = 10, divisor = 3;

    Solution sol;
    int ans = sol.divide(dividend, divisor);

    cout << "The result of dividing " << dividend << " and " << divisor << " is " << ans;
    return 0;
}
