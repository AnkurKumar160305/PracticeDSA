//Using recursion
class Solution {
    int solve(string &s,int i,int n,int sign,long long num){
        if(i>=n || s[i]<'0' || s[i]>'9'){
            return (int)(sign*num);
        }
        
        num=num*10+s[i]-'0';
        if(num*sign<=INT_MIN){
            return INT_MIN;
        }
        if(num*sign>=INT_MAX){
            return INT_MAX;
        }
        return solve(s,i+1,n,sign,num);
    }
public:
    int myAtoi(string s) {
        int i=0,n=s.size();
        int sign=1;

        while(i<n && s[i]==' '){
            i++;
        }
        if(i<n && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        return solve(s,i,n,sign,0);
    }
};




class Solution {
public:
    int myAtoi(string s) {
        int i=0,n=s.size();
        int sign=1;
        long long num=0;
        while(i<n && s[i]==' '){
            i++;
        }
        if(s[i]=='+' || s[i]=='-'){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        while(i<n && s[i]>='0' && s[i]<='9'){
            num=num*10+(s[i]-'0');
            if(num*sign<=INT_MIN){
                return INT_MIN;
            }
            if(num*sign>=INT_MAX){
                return INT_MAX;
            }
            i++;
        }
        return (int)(sign*num);
    }
};