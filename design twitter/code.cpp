class Twitter {
private:
    unordered_map<int, vector<pair<int, int>>> user_post;
    unordered_map<int, unordered_set<int>> user_follow;
    int time = 0;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        user_post[userId].push_back({time++, tweetId});

        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> tweets;

        user_follow[userId].insert(userId);

        for(auto follower : user_follow[userId]){
            for(auto tweet : user_post[follower]){
                tweets.push(tweet);
            }
        }

        vector<int> result;
        while(!tweets.empty() && result.size() < 10){
            int tweetid = tweets.top().second;
            tweets.pop();
            result.push_back(tweetid);
        }

        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            user_follow[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        user_follow[followerId].erase(followeeId);
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