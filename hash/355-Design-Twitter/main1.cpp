#include <cassert>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Twitter {
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    int clock = 0;
public:
    Twitter() = default;
    void postTweet(int userId, int tweetId) { tweets[userId].emplace_back(++clock,
tweetId); }
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int>> pq;
        unordered_set<int> users = following.count(userId) ? following[userId] :
unordered_set<int>{};
        users.insert(userId);
        for (const int u : users) {
            unordered_map<int, vector<pair<int, int>>>::iterator it = tweets.find(u);
            if (it != tweets.end() && !it->second.empty()) {
                const int last = it->second.size() - 1;
                pq.emplace(it->second[last].first, u, last);
            }
        }
        vector<int> res; res.reserve(10);
        while (!pq.empty() && res.size() < 10) {
            const auto [_, u, i] = pq.top(); pq.pop();
            res.push_back(tweets[u][i].second);
            if (i > 0) pq.emplace(tweets[u][i - 1].first, u, i - 1);
        }
        return res;
    }
    void follow(int followerId, int followeeId) { following[followerId].insert(followeeId); }
    void unfollow(int followerId, int followeeId) { unordered_map<int, unordered_set<int>>::iterator it = following.find(followerId); if (it != following.end()) it->second.erase(followeeId); }
};

int main()
{
    Twitter twitter;
    twitter.postTweet(1, 5);
    vector<int> res1 = {5};
    assert(twitter.getNewsFeed(1) == res1);
    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    vector<int> res2 = {6, 5};
    assert(twitter.getNewsFeed(1) == res2);
    twitter.unfollow(1, 2);
    vector<int> res3 = {5};
    assert(twitter.getNewsFeed(1) == res3);
    return 0;
}
