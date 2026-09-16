#include <cassert>
#include <vector>

using namespace std;

class Solution {
    static constexpr int MOD = 1'000'000'007;
    long long power(long long base, long long exp) const {
        long long res = 1;
        for (base %= MOD; exp; exp >>= 1, base = base * base % MOD) if (exp & 1) res = res * base % MOD;
        return res;
    }
public:
    int numberOfSets(int n, int k) {
        const int total = n + k - 1, r = 2 * k;
        long long num = 1, den = 1;
        for (int i = 0; i < r; ++i) { num = num * ((total - i) % MOD) % MOD; den = den * (i + 1) % MOD; }
        return num * power(den, MOD - 2) % MOD;
    }
};

int main()
{
    Solution s;
    assert(s.numberOfSets(4, 2) == 5);
    assert(s.numberOfSets(3, 1) == 3);
    assert(s.numberOfSets(30, 7) == 796297179);
    return 0;
}
