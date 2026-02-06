class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()>0 && s.find(part)<s.length()){
            int x=s.find(part);
            s.erase(x,part.length());
        }
        return s;
    }
};


class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size();
        int m=part.size();
        if(m>n){
            return "";
        }

        for(int r=0;r+m<=n;){
            int l=0;
            while(l<m && s[r+l]==part[l]){
                l++;
            }
            if(l==m){
                s.erase(r,m);
                r=max(0,r-m);
            }else{
                r++;
            }
        }
        return s;
    }
};


class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size();
        int m=part.size();
        int i=-1;
        int j=0,k=0;
        while(j<n && k<m){
            if(s[j]==part[k]){
                if(k==0){
                    i=j;
                }
                j++;
                k++;
                if(k==m){
                    for (int x = i + m; x < n; x++) {
                        s[x - m] = s[x];
                    }
                    n -= m;          
                    j = max(0, i - 1); 
                    k = 0;
                    i = -1;
                }
            }else if(k>0){
                j = i + 1;
                k = 0;
                i = -1;
            }else {
                j++;
            }
        }
        return s.substr(0, n);
    }
};