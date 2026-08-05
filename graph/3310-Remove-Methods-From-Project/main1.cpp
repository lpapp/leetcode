#include <cassert>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        for (const vector<int>& inv : invocations) graph[inv[0]].push_back(inv[1]);
        vector<bool> suspicious(n, false);
        suspicious[k] = true;
        for (queue<int> q({k}); !q.empty(); ) {
            const int cur = q.front(); q.pop();
            for (const int next : graph[cur]) {
                if (suspicious[next]) continue;
                suspicious[next] = true;
                q.push(next);
            }
        }
        for (const vector<int>& inv : invocations) {
            if (!suspicious[inv[0]] && suspicious[inv[1]]) {
                vector<int> res(n);
                iota(res.begin(), res.end(), 0);
                return res;
            }
        }
        vector<int> res;
        for (int i = 0; i < n; ++i) if (!suspicious[i]) res.push_back(i);
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> invocations1 = {{1, 2}, {0, 1}, {3, 2}};
    vector<int> res1 = {0, 1, 2, 3};
    assert(s.remainingMethods(4, 1, invocations1) == res1);

    vector<vector<int>> invocations2 = {{1, 2}, {0, 2}, {0, 1}, {3, 4}};
    vector<int> res2 = {3, 4};
    assert(s.remainingMethods(5, 0, invocations2) == res2);

    vector<vector<int>> invocations3 = {{1, 2}, {0, 1}, {2, 0}};
    vector<int> res3 = {};
    assert(s.remainingMethods(3, 2, invocations3) == res3);
    return 0;
}
