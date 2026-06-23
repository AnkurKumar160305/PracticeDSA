class Solution {
public:
    int arrangeCoins(int n) {
        int row=0;

        while(row+1<=n){
            row++;
            n-=row;
        }

        return row;
        
    }
};


//OR
class Solution {
public:
    int arrangeCoins(int n) {
        long long low = 1, high = n;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long coins = mid * (mid + 1) / 2;

            if (coins == n)
                return mid;
            else if (coins < n)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};



//Optimal
//To build k complete rows, you need:
//1+2+3+⋯+k=k(k+1)/2

//We need the largest k such that:
//k(k+1)/2≤n

//Multiply by 2:
//k^2+k≤2n

//Solve the quadratic equation:
//k^2+k−2n=0

//Using the quadratic formula:
//k=(-1±√(1+8n))/2

// Since k must be positive:
// k=(-1+√(1+8n))/2

class Solution {
public:
    int arrangeCoins(int n) {

        return (sqrt(1 + 8.0 * n) - 1) / 2;
        
    }
};