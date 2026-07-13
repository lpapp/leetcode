#include <algorithm>
#include <cassert>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        const int n = friends.size();
        vector<bool> vis(n);
        vis[id] = true;
        queue<int> q{{id}};
        for (int lv = 0; lv < level; ++lv) for (int i = 0, sz = q.size(); i < sz; ++i) {
            const int u = q.front(); q.pop();
            for (const int v : friends[u]) if (!vis[v]) { vis[v] = true; q.push(v); }
        }
        unordered_map<string, int> freq;
        for (; !q.empty(); q.pop()) for (const string& v : watchedVideos[q.front()]) ++freq[v];
        vector<pair<int, string>> pairs;
        pairs.reserve(freq.size());
        for (auto& [name, cnt] : freq) pairs.emplace_back(cnt, std::move(name));
        ranges::sort(pairs);
        vector<string> res;
        res.reserve(pairs.size());
        for (auto& [cnt, name] : pairs) res.push_back(std::move(name));
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> watchedVideos1 = {{"A", "B"}, {"C"}, {"B", "C"}, {"D"}};
    vector<vector<int>> friends1 = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    vector<string> res1 = {"B", "C"};
    assert(s.watchedVideosByFriends(watchedVideos1, friends1, 0, 1) == res1);

    vector<vector<string>> watchedVideos2 = {{"A", "B"}, {"C"}, {"B", "C"}, {"D"}};
    vector<vector<int>> friends2 = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    vector<string> res2 = {"D"};
    assert(s.watchedVideosByFriends(watchedVideos1, friends1, 0, 2) == res2);
    return 0;
}
