class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize){
            return false;
        }

        map<int,int> m;

        for(auto h:hand){
            m[h]++;
        }

        while(!m.empty()){
            int curr=m.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(m[curr+i]==0){
                    return false;
                }
                m[curr+i]--;
                if(m[curr+i]<1){
                    m.erase(curr+i);
                }
            }
        }

        return true;
    }
};