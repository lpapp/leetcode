#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
    long long count(long long num, int k) {
        if (num < 10) return num;
        const string s = to_string(num);
        const int n = s.size();
        long long dp[11][2][2] = {}; dp[0][1][0] = 1;
        for (int pos = 0; pos < n; ++pos) {
            long long ndp[11][2][2] = {};
            for (int last = 0; last <= 10; ++last) {
                for (int tight = 0; tight < 2; ++tight) {
                    for (int started = 0; started < 2; ++started) {
                        if (!dp[last][tight][started]) continue;
                        const int limit = tight ? s[pos] - '0' : 9;
                        for (int d = 0; d <= limit; ++d) {
                            const bool nt = tight && d == limit;
                            if (!started && !d) ndp[0][nt][0] += dp[last][tight][started];
                            else if (!started || abs(d - (last - 1)) <= k) ndp[d + 1][nt][1] += dp[last][tight][started];
                        }
                    }
                }
            }
            memcpy(dp, ndp, sizeof(dp));
        }
        long long res = 0;
        for (int last = 0; last <= 10; ++last) for (int tight = 0; tight < 2; ++tight) res += dp[last][tight][1];
        return res;
    }
public:
    long long goodIntegers(long long l, long long r, int k) {
        return count(r, k) - count(l - 1, k);
    }
};

int main()
{
	Solution s;
    assert(s.goodIntegers(10, 15, 1) == 3);
    assert(s.goodIntegers(201, 204, 2) == 2);
	return 0;
}
