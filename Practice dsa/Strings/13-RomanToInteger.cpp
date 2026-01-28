class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int sum=0;
        int prev=0;
        for(int i=s.size()-1;i>=0;i--){
            int curr=m[s[i]];
            if(curr<prev){
                sum-=m[s[i]];
            }else{
                sum+=m[s[i]];
            }
            prev=curr;
        }
        return sum;
    }
};

//Optimal

class Solution {
public:
    int value(char c) {
        if (c == 'I') return 1;
        else if (c == 'V') return 5;
        else if (c == 'X') return 10;
        else if (c == 'L') return 50;
        else if (c == 'C') return 100;
        else if (c == 'D') return 500;
        else if (c == 'M') return 1000;
        return 0;
    }

    int romanToInt(string s) {
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (i + 1 < n && value(s[i]) < value(s[i + 1])) {
                ans -= value(s[i]);
            } else {
                ans += value(s[i]);
            }
        }

        return ans;
    }
};
