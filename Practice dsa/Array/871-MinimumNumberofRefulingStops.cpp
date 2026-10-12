//Minimum Number of Refueling Stops
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> q;
        int fuel=startFuel;
        int cnt=0;
        int i=0;
        int n=stations.size();

        while(fuel<target){
            while(i<n && stations[i][0]<=fuel){
                q.push(stations[i][1]);
                i++;
            }
            if(q.empty()){
                return -1;
            }
            fuel+=q.top();
            q.pop();
            cnt++;
        }
        return cnt;
    }
};