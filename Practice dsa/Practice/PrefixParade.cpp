#include <bits/stdc++.h>
using namespace std;

int countPrefixes(vector<string>& words, string s) {
    int count = 0;
    
    for (string &word : words) {
        // check if word is prefix of s
        if (s.rfind(word, 0) == 0) {
            count++;
        }
        //OR
        // if(s.substr(0,word.length())==word){
        //     count++;
        // }
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;
    
    vector<string> words(n);
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }
    
    string s;
    cin >> s;
    
    cout << countPrefixes(words, s);
}