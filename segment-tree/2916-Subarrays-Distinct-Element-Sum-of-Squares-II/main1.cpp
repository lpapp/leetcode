#include <cassert>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    int n;
    vector<long long> sum, sumSq, lazy;
    void apply(int node, int len, long long add) {
        sumSq[node] = (sumSq[node] + 2 * add % MOD * sum[node] + add % MOD * add % MOD * len) % MOD;
        sum[node] = (sum[node] + add % MOD * len) % MOD;
        lazy[node] = (lazy[node] + add) % MOD;
    }
    void push(int node, int left, int right) {
        if (!lazy[node]) return;
        const int mid = (left + right) / 2;
        apply(2 * node, mid - left + 1, lazy[node]);
        apply(2 * node + 1, right - mid, lazy[node]);
        lazy[node] = 0;
    }
    void update(int node, int left, int right, int ql, int qr) {
        if (qr < left || right < ql) return;
        if (ql <= left && right <= qr) { apply(node, right - left + 1, 1); return; }
        push(node, left, right);
        const int mid = (left + right) / 2;
        update(2 * node, left, mid, ql, qr);
        update(2 * node + 1, mid + 1, right, ql, qr);
        sum[node] = (sum[2 * node] + sum[2 * node + 1]) % MOD;
        sumSq[node] = (sumSq[2 * node] + sumSq[2 * node + 1]) % MOD;
    }

public:
    static constexpr long long MOD = 1'000'000'007;
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sum.assign(4 * n, 0), sumSq.assign(4 * n, 0), lazy.assign(4 * n, 0);
        unordered_map<int, int> last;
        long long res = 0;
        for (int j = 0; j < n; ++j) {
            const int p = last.count(nums[j]) ? last[nums[j]] : -1;
            update(1, 0, n - 1, p + 1, j);
            last[nums[j]] = j;
            res = (res + sumSq[1]) % MOD;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 1};
    assert(s.sumCounts(nums1) == 15);
    vector<int> nums2 = {2, 2};
    assert(s.sumCounts(nums2) == 3);
    return 0;
}
