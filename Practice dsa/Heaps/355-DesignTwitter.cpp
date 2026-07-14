class Twitter {
public:
    int timer;

    // user -> set of users he follows
    unordered_map<int, unordered_set<int>> follows;

    // user -> list of {time, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweets;

    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;

        // User should always see his own tweets
        follows[userId].insert(userId);

         // Push all tweets of user and followees
        for(auto followee : follows[userId]) {
            for(auto tweet : tweets[followee]) {
                pq.push(tweet);
            }
        }

        vector<int> ans;

        while(!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return;

        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return;

        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */