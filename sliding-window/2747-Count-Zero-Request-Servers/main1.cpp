#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        const int maxTime = ranges::max(queries);
        vector<int> start(maxTime + 2), server(logs.size()), count(n + 1), zero(maxTime + 
1), res; res.reserve(queries.size());
        for (const vector<int>& log : logs) if (log[1] <= maxTime) ++start[log[1] + 1];
        partial_sum(start.cbegin(), start.cend(), start.begin());
        for (const vector<int>& log : logs) if (log[1] <= maxTime) server[start[log[1]]++]
 = log[0];
        for (int time = 1, active = 0, added = 0, removed = 0; time <= maxTime; ++time) {
            for (; added < start[time]; ++added) if (!count[server[added]]++) ++active;
            if (time > x) for (; removed < start[time - x - 1]; ++removed) if (!--count[server[removed]]) --active;
            zero[time] = n - active;
        }
        for (const int query : queries) res.push_back(zero[query]);
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
    return 0;
}
