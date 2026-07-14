//using maxHeap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        if(n<k){
            return ans;
        }

        unordered_map<int,int> m;

        for(auto i:nums){
            m[i]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto it:m){
            pq.push({it.second,it.first});
        }

        while(k--){
            int temp=pq.top().second;
            pq.pop();
            ans.push_back(temp);
        }

        return ans;

    }
};

//using minHeap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        if(n<k){
            return ans;
        }

        unordered_map<int,int> m;

        for(auto i:nums){
            m[i]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(auto it:m){
            pq.push({it.second,it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }
};