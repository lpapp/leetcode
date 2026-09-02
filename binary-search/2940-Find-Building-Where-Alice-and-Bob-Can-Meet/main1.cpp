#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        const int n = heights.size(), m = queries.size();
        vector<int> res(m, -1), order(m);
        iota(order.begin(), order.end(), 0);
        for (vector<int>& q : queries) if (q[0] > q[1]) swap(q[0], q[1]);
        ranges::sort(order, [&queries](const int a, const int b) { return queries[a][1] > queries[b][1]; });
        vector<int> s; s.reserve(n);
        int j = n - 1;
        for (const int qi : order) {
            const int l = queries[qi][0], r = queries[qi][1];
            while (j > r) {
                while (!s.empty() && heights[s.back()] <= heights[j]) s.pop_back();
                s.push_back(j--);
            }
            if (l == r || heights[l] < heights[r]) { res[qi] = r; continue; }
            int lo = 0, hi = s.size() - 1, best = -1;
            while (lo <= hi) {
                const int mid = lo + (hi - lo) / 2;
                if (heights[s[mid]] > heights[l]) { best = s[mid]; lo = mid + 1; }
                else hi = mid - 1;
            }
            res[qi] = best;
        }
        return res;       
    }
};

int main()
{
    Solution s;
    vector<int> heights1 = {6, 4, 8, 5, 2, 7};
    vector<vector<int>> queries1 = {{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}};
    vector<int> res1 = {2, 5, -1, 5, 2};
    assert(s.leftmostBuildingQueries(heights1, queries1) == res1);
    vector<int> heights2 = {5, 3, 8, 2, 6, 1, 4, 6};
    vector<vector<int>> queries2 = {{0, 7}, {3, 5}, {5, 2}, {3, 0}, {1, 6}};
    vector<int> res2 = {7, 6, -1, 4, 6};
    assert(s.leftmostBuildingQueries(heights2, queries2) == res2);
    return 0;
}
