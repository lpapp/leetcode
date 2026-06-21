#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
    static const int MOD = 1e9 + 7;
    static const long long INV2 = 500000004LL;
    pair<long long, long long> compute(vector<int>& value, vector<int>& decay, long long t, int n) {
        long long count = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            if (value[i] < t) continue;
            long long c = (value[i] - t) / decay[i] + 1;
            count += c;
            long long term = c % MOD * (value[i] % MOD) % MOD;
            long long sub = static_cast<long long>(decay[i]) % MOD * (c% MOD) % MOD * ((c-1) % MOD) % MOD * INV2 % MOD;
            sum = (sum + term - sub + MOD) % MOD;
        }
        return {count, sum};
    }
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        const int MOD = 1e9 + 7;
        int n = value.size();
        long long l = 0, r = ranges::max(value);
        while (l < r) {
            long long mid = (l + r + 1) >> 1;
            auto [count, s] = compute(value, decay, mid, n);
            if (count >= m) l = mid;
            else r = mid - 1;
        }
        auto [count, sum] = compute(value, decay, l, n);
        long long excess = (count - m) % MOD * (l % MOD) % MOD;
        return (sum - excess  + MOD) % MOD;
    }
};

int main()
{
    Solution s;
    vector<int> value1 = {6, 5, 4};
    vector<int> decay1 = {2, 1, 1};
    assert(s.maxTotalValue(value1, decay1, 4) == 19);
    vector<int> value2 = {7, 2, 2};
    vector<int> decay2 = {3, 2, 1};
    assert(s.maxTotalValue(value2, decay2, 2) == 11);
    vector<int> value3 = {4, 3};
    vector<int> decay3 = {5, 4};
    assert(s.maxTotalValue(value3, decay3, 5) == 7);
    return 0;
}
