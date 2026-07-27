class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());

        vector<vector<string>> ans;
        
        if (!st.count(endWord)) return ans;

        queue<vector<string>> q;
        q.push({beginWord});

        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);

        int level = 0;

        while(!q.empty()){
            vector<string> vec=q.front();
            q.pop();
            //erase all words in previous level that has been used to transformed
            if(vec.size()>level){
                level++;
                for(auto it:usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear();
            }
            string word=vec.back();

            if(word==endWord){
                if(ans.size()==0){
                    ans.push_back(vec);
                }else if(ans[0].size()==vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i=0;i<word.size();i++){
                char org=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)>0){
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i]=org;
            }
        }

        return ans;
    }
};