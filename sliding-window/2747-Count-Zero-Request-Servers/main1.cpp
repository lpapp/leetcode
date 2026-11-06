#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        const int logCount = logs.size(), queryCount = queries.size();
        vector<pair<int, int>> events, sortedQueries; events.reserve(logCount); sortedQueries.reserve(queryCount);
        for (const vector<int>& log : logs) events.emplace_back(log[1], log[0]);
        for (int i = 0; i < queryCount; ++i) sortedQueries.emplace_back(queries[i], i);
        ranges::sort(events);
        ranges::sort(sortedQueries);
        vector<int> count(n + 1), res(queryCount);
        for (int added = 0, removed = 0, active = 0; const auto& [query, index] : sortedQueries) {
            for (; added < logCount && events[added].first <= query; ++added) if (!count[events[added].second]++) ++active;
            for (; removed < added && events[removed].first < query - x; ++removed) if (!--count[events[removed].second]) --active;
            res[index] = n - active;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> logs1 = {{1, 3}, {2, 6}, {1, 5}};
    vector<int> queries1 = {10, 11};
    vector<int> res1 = {1, 2};
    assert(s.countServers(3, logs1, 5, queries1) == res1);
    vector<vector<int>> logs2 = {{2, 4}, {2, 1}, {1, 2}, {3, 1}};
    vector<int> queries2 = {10, 11};
    vector<int> res2 = {0, 1};
    assert(s.countServers(3, logs2, 2, queries2) == res2);
    vector<vector<int>> logs3 = {{1, 505273}};
    vector<int> queries3 = {847895};
    vector<int> res3 = {0, 1};
    assert(s.countServers(1, logs3, 30316, queries3) == res3);
    return 0;
}
