#include<bits/stdc++.h>
using namespace std;

void Sortstring(string &s){
    vector<int> mp(26,0);
    for(int i=0;i<s.length();i++){
        mp[s[i]-'a']++;
    }
    string v="";
    for(int i=0;i<26;i++){
        while(mp[i]>0){
            v+=(char)(i+'a');
            mp[i]--;
        }
    }
    s=v;
}

int main(){
    string s="bdcae";
    Sortstring(s);
    cout<<s;
}