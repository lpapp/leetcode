#include <array>
#include <cassert>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        constexpr long long MOD = 1'000'000'007;
        array<long long, 26> dp{};
        for (const char ch : s) dp[ch - 'a'] = accumulate(dp.cbegin(), dp.cend(), 1LL) % MOD;
        return static_cast<int>(accumulate(dp.cbegin(), dp.cend(), 0LL) % MOD);
    }
};

int main()
{
    Solution s;
    assert(s.distinctSubseqII("abc") == 7);
    assert(s.distinctSubseqII("aba") == 6);
    assert(s.distinctSubseqII("aaa") == 3);
    return 0;
}
