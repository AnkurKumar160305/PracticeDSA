string solve(const string &str1, const string &str2) {
    // add your code here
    if(str1+str2!=str2+str1){
        return "";
    }
    int len=__gcd(str1.length(),str2.length());
    return str1.substr(0,len);
}