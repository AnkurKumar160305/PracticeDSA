class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1){
            sort(stones.begin(),stones.end());
            int y=stones.back();
            stones.pop_back();
            int x=stones.back();
            stones.pop_back();

            if(x!=y){
                stones.push_back(abs(x-y));
            }
        }
        return stones.empty()? 0 : stones[0];
    }
};


//Optimal
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int x:stones){
            pq.push(x);
        }

        while(pq.size()>1){
            int y=pq.top();
            pq.pop();
            int x=pq.top();
            pq.pop();

            if(x!=y){
                pq.push(abs(x-y));
            }
        }
        return pq.empty()? 0 : pq.top();
    }
};