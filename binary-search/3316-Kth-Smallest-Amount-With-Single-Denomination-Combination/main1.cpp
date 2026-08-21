#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        const int n = coins.size();
        const long long hi = (long long)k * ranges::min(coins);
        vector<pair<long long, int>> terms;
        for (int mask = 1; mask < (1 << n); ++mask) {
            long long lcm = 1;
            for (int i = 0, ok = 1; i < n && ok; ++i) {
                if (!(mask & (1 << i))) continue;
                lcm = lcm / gcd(lcm, (long long)coins[i]) * coins[i];
                if (lcm > hi) { lcm = 0; ok = 0; }
            }
            if (lcm) terms.emplace_back(lcm, __builtin_popcount(mask) & 1 ? 1 : -1);
        }
        for (long long lo = 1, r = hi; ; ) {
            if (lo >= r) return lo;
            const long long mid = lo + (r - lo) / 2;
            long long count = 0;
            for (const pair<long long, int> term : terms) count += term.second * (mid / term.first);
            if (count >= k) r = mid;
            else lo = mid + 1;
        }       
    }
};

int main()
{
    Solution s;
    vector<int> coins1 = {3, 6, 9};
    assert(s.findKthSmallest(coins1, 3) == 9);
    vector<int> coins2 = {5, 2};
    assert(s.findKthSmallest(coins2, 7) == 12);
    return 0;
}
