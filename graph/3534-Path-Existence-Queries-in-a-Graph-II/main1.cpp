#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        ranges::sort(order, [&](int a, int b) { return nums[a] < nums[b]; });
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) pos[order[i]] = i;
        vector<int> sorted_vals(n);
        for (int i = 0; i < n; ++i) sorted_vals[i] = nums[order[i]];
        constexpr int LOG = 17;
        vector<vector<int>> jump(LOG, vector<int>(n));
        for (int i = 0; i < n; ++i) jump[0][i] = (int)(upper_bound(sorted_vals.begin(), sorted_vals.end(), sorted_vals[i] + maxDiff) - sorted_vals.begin()) - 1;
        for (int k = 1; k < LOG; ++k) for (int i = 0; i < n; ++i) jump[k][i] = jump[k - 1][jump[k - 1][i]];
        vector<int> component(n);
        for (int i = 1, id = 0; i < n; ++i) { if (sorted_vals[i] - sorted_vals[i - 1] > maxDiff) ++id; component[i] = id; }
        vector<int> res;
        res.reserve(queries.size());
        for (const vector<int>& q : queries) {
            int u = pos[q[0]], v = pos[q[1]];
            if (u > v) swap(u, v);
            if (u == v) { res.push_back(0); continue; }
            if (component[u] != component[v]) { res.push_back(-1); continue; }
            int hops = 0;
            for (int k = LOG - 1; k >= 0; --k) if (jump[k][u] < v) { u = jump[k][u]; hops += (1 << k); }
            res.push_back(hops + 1);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 8, 3, 4, 2};
    vector<vector<int>> queries1 = {{0, 3}, {2, 4}}; 
    vector<int> res1 = {1, 1};
    assert(s.pathExistenceQueries(5, nums1, 3, queries1) == res1);

    vector<int> nums2 = {5, 3, 1, 9, 10};
    vector<vector<int>> queries2 = {{0, 1}, {0, 2}, {2, 3}, {4, 3}}; 
    vector<int> res2 = {1, 2, -1, 1};
    assert(s.pathExistenceQueries(5, nums2, 2, queries2) == res2);

    vector<int> nums3 = {3, 6, 1};
    vector<vector<int>> queries3 = {{0, 0}, {0, 1}, {1, 2}}; 
    vector<int> res3 = {0, -1, -1};
    assert(s.pathExistenceQueries(3, nums3, 1, queries3) == res3);
    return 0;
}
