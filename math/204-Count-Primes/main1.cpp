#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        const int m = (n - 1) / 2;
        vector<char> composite(m + 1, 0);
        int count = 1;
        for (int i = 1; i <= m; ++i) {
            const int p = 2 * i + 1;
            if (p >= n) break;
            if (!composite[i]) {
                ++count;
                for (long long j = (long long)p * p; j < n; j += 2 * p) composite[(j - 1) / 2] = 1;
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    assert(s.countPrimes(10) == 4);
    assert(s.countPrimes(0) == 0);
    assert(s.countPrimes(1) == 0);
    return 0;
}
