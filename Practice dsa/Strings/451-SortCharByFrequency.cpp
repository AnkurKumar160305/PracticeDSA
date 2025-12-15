class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int,char>> pq;
        for(auto i:freq){
            pq.push({i.second,i.first});
        }
        string str="";
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int count=top.first;
            char ch=top.second;
            while(count){
                str+=ch;
                count--;
            }
        }
        return str;
    }
};