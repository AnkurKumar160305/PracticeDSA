#include<bits/stdc++.h>
using namespace std;

// int countSubstrings(string s, int k) {
//     int n=s.size();
//     vector<string> sub;
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             sub.push_back(s.substr(i,j-i+1));
//         }
//     }
//     int cnt = 0;
//     for (auto str : sub) {
//         set<char> st;
//         for (char c : str) st.insert(c);
//         if (st.size() == k) cnt++;
//     }
//     return cnt;
// }

//Optimal
int countSubstrings(string s, int k) {
    int n=s.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        unordered_map<char,int> freq;
        for(int j=i;j<n;j++){
            freq[s[j]]++;
            if(freq.size()==k){
                cnt++;
            }else if(freq.size()>k){
                break;
            }
        }
    }
    return cnt;
}

int main() {
    // Sample test
    string s = "pqpqs";
    int k = 2;

    // Output the result
    cout << "Count: " << countSubstrings(s, k) << endl; // Output: 7
    return 0;
}