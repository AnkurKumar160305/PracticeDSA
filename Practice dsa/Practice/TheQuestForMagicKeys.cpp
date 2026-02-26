bool canVisitAllRooms(vector<vector<int>>& rooms) {
    // add your code here
    int n=rooms.size();
    queue<int> q;
    vector<bool> vis(n,false);
    q.push(0);
    vis[0]=true;
    int cnt=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int key:rooms[curr]){
            if(!vis[key]){
                vis[key]=true;
                q.push(key);
                cnt++;
            }
        }
    }
    return cnt==n;
}