#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if (right < 2) return {-1, -1};
        const int m = (right - 1) / 2;
        vector<char> composite(m + 1, 0);
        for (int i = 1; i <= m; ++i) {
            const int p = 2 * i + 1;
            if ((long long)p * p > right) break;
            if (!composite[i])
                for (long long j = (long long)p * p; j <= right; j += 2 * p) composite[(j - 1) / 2] = 1;
        }
        auto isPrime = [&](int x) {
            if (x < 2) return false;
            if (x == 2) return true;
            if ((x & 1) == 0) return false;
            return composite[(x - 1) / 2] == 0;
        };
        int prev = -1, bestA = -1, bestB = -1, bestGap = INT_MAX;
        for (int p = max(left, 2); p <= right; ++p)
            if (isPrime(p)) {
                if (prev != -1 && p - prev < bestGap) { bestGap = p - prev; bestA = prev; bestB = p; }
                prev = p;
            }
        return {bestA, bestB};
    }
};

int main()
{
    Solution s;
    vector<int> res1 = {11, 13};
    assert(s.closestPrimes(10, 19) == res1);
    vector<int> res2 = {-1, -1};
    assert(s.closestPrimes(4, 6) == res2);
    return 0;
}
