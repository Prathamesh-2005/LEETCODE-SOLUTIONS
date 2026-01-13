class Twitter {
public:
    unordered_map<int, vector<pair<int,int>>> tweets;
    int count;
    unordered_map<int,set<int>>mp;
    Twitter() {
        count=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({count++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;

        for (auto &t : tweets[userId]) {
            pq.push(t);
        }

        for (int f : mp[userId]) {
            for (auto &t : tweets[f]) {
                pq.push(t);
            }
        }

        while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp.erase(followerId);
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