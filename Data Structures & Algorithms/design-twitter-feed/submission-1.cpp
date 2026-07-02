class Twitter {
public:
    //Global time variable to keep track of the latest tweets
    int time = 0;
    //Data structure to store follow/unfollow
    unordered_map<int,unordered_set<int>> followees;
    //Data structure to store tweets
    unordered_map<int,vector<pair<int,int>>> tweets;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        //use max heap to get most recent top 10 tweets
        priority_queue<pair<int,int>> pq;
        // Get users own tweets
        for(auto it : tweets[userId]){
            pq.push(it);
        }
        //Get users followee tweets
        for(auto followeeID : followees[userId]){
            for(auto ftweet : tweets[followeeID]){
                pq.push(ftweet);
            }
        }
        //Get top 10 tweets
        int count = 0;
        vector<int> res;
        while(!pq.empty() && count < 10){
            res.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return ;
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};
