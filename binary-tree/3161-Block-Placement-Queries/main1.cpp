#include <algorithm>
#include <cassert>
#include <set>
#include <vector>

using namespace std;

class Solution {
    void update(vector<int>& seg, int N, int i, int val) {
        i += N;
        seg[i] = val;
        for (i >>= 1; i >= 1; i >>= 1) seg[i] = max(seg[2*i], seg[2*i+1]);
    }
    int query(vector<int>& seg, int N, int l, int r) {
        int res = 0;
        for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, seg[l++]);
            if (r & 1) res = max(res, seg[--r]);
        }
        return res;
    }
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        const int N = min(50001, static_cast<int>(queries.size()) * 3 + 1);
        vector<int> seg(2 * N, 0);
        set<int> obstacles = {0};
        vector<bool> res;
        for (auto& q : queries) {
            if (q[0] == 1) {
                const int x = q[1];
                auto it = obstacles.insert(x).first;
                update(seg, N, x, x - *prev(it));
                auto nxt = next(it);
                if (nxt != obstacles.end()) update(seg, N, *nxt, *nxt - x);
            } else {
                const int x = q[1];
                auto it = prev(obstacles.upper_bound(x));
                const int maxGap = max(query(seg, N, 0, x), x - *it);
                res.push_back(maxGap >= q[2]);
            }
        }
        return res;
    }
};

int main()
{
	Solution s;
    vector<vector<int>> queries1 = {{1, 2}, {2, 3, 3}, {2, 3, 1}, {2, 2, 2}};
    vector<bool> res1 = {false, true, true};
	assert(s.getResults(queries1) == res1);
    vector<vector<int>> queries2 = {{1, 7}, {2, 7, 6}, {1, 2}, {2, 7, 5}, {2, 7, 6}};
    vector<bool> res2 = {true, true, false};
	assert(s.getResults(queries2) == res2);
	return 0;
}
