#include <cassert>
#include <vector>

using namespace std;

class Solution {
    static constexpr int MOD = 1e9 + 7;
    vector<vector<long long>> C;
    vector<int> L, R, val;
    int root = -1, idx = 0;
    int insert(int r, int x) {
        if (r == -1) {
            val[idx] = x;
            L[idx] = R[idx] = -1;
            return idx++;
        }
        if (x < val[r]) L[r] = insert(L[r], x);
        else R[r] = insert(R[r], x);
        return r;
    }
    pair<long long, long long> dfs(int r) {
        if (r == -1) return {0, 1};
        const auto [ls, lw] = dfs(L[r]);
        const auto [rs, rw] = dfs(R[r]);
        return {ls + rs + 1, C[ls + rs][ls] % MOD * lw % MOD * rw % MOD};
    }
public:
    int numOfWays(vector<int>& nums) {
        const int n = nums.size();
        L.assign(n, -1); R.assign(n, -1); val.assign(n, 0); C.assign(n + 1, vector<long long>(n + 1, 0));
        root = -1; idx = 0;
        for (int i = 0; i <= n; ++i) {
            C[i][0] = 1;
            for (int j = 1; j <= i; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
        for (const int x : nums) root = insert(root, x);
        return (dfs(root).second - 1 + MOD) % MOD;
    }       
};

int main()
{
    Solution s;
    vector<int> nums1 = {2, 1, 3};
    assert(s.numOfWays(nums1) == 1);
    vector<int> nums2 = {3, 4, 5, 1, 2};
    assert(s.numOfWays(nums2) == 5);
    vector<int> nums3 = {1, 2, 3};
    assert(s.numOfWays(nums3) == 0);
    return 0;
}
