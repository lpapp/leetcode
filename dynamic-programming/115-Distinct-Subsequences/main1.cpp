#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        const int n = t.size();
        vector<unsigned long long> dp(n + 1, 0); dp[0] = 1;
        for (const char c : s) for (int j = n; j >= 1; --j) if (c == t[j - 1]) dp[j] += dp[j - 1];
        return static_cast<int>(dp[n]);
    }
};

int main()
{
    Solution s;
    assert(s.numDistinct("rabbbit", "rabbit") == 3);
    assert(s.numDistinct("babgbag", "bag") == 5);
    return 0;
}
