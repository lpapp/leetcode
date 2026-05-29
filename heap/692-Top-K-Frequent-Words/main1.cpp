#include <cassert>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash;
        for (const string& word : words) ++hash[word];
        auto cmp = [](const pair<int, string>& a, const pair<int, string>& b) { return a.first != b.first ? a.first > b.first : a.second < b.second; };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);
        for (auto& [word, count] : hash) { pq.push({count, word}); if (static_cast<int>(pq.size()) > k) pq.pop(); }
        vector<string> res(k);
        for (int i = k - 1; i >= 0; res[i--] = pq.top().second, pq.pop());
        return res;       
    }
};

int main()
{
    Solution s;
    vector<string> words1 = {"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> res1 = {"i", "love"};
    assert(s.topKFrequent(words1, 2) == res1);
    vector<string> words2 = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    vector<string> res2 = {"the", "is", "sunny", "day"};
    assert(s.topKFrequent(words2, 4) == res2);
    return 0;
}
