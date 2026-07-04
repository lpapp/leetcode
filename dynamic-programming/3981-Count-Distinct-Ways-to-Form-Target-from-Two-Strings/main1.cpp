#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int interleaveCharacters(string word1, string word2, string target) {
        constexpr int MOD = 1'000'000'007;
        const int n1 = word1.size(), n2 = word2.size(), m = target.size();
        vector<vector<long long>> f(n1 + 1, vector<long long>(n2 + 1, 0)); f[0][0] = 1;
        for (int k = 0; k < m; ++k) {
            vector<vector<long long>> CS(n1 + 1, vector<long long>(n2 + 1, 0));
            vector<vector<long long>> CT(n1 + 1, vector<long long>(n2 + 1, 0));
            for (int b = 0; b <= n2; ++b) {
                CS[0][b] = f[0][b];
                for (int a = 1; a <= n1; ++a) CS[a][b] = (CS[a - 1][b] + f[a][b]) % MOD;
            }
            for (int a = 0; a <= n1; ++a) {
                CT[a][0] = f[a][0];
                for (int b = 1; b <= n2; ++b) CT[a][b] = (CT[a][b - 1] + f[a][b]) % MOD;
            }
            vector<vector<long long>> nf(n1 + 1, vector<long long>(n2 + 1, 0));
            for (int a = 0; a <= n1; ++a) {
                for (int b = 0; b <= n2; ++b) {
                    long long v = 0;
                    if (a >= 1 && word1[a - 1] == target[k]) v = (v + CS[a - 1][b]) % MOD;
                    if (b >= 1 && word2[b - 1] == target[k]) v = (v + CT[a][b - 1]) % MOD;
                    nf[a][b] = v;
                }
            }
            f = std::move(nf);
        }
        long long total = 0;
        for (int a = 0; a <= n1; ++a) for (int b = 0; b <= n2; ++b) total = (total + f[a][b]) % MOD;
        auto subseqCount = [&](const string& s, const string& t) -> long long {
            const int ns = s.size(), nt = t.size();
            vector<vector<long long>> dp(nt + 1, vector<long long>(ns + 1, 0));
            for (int j = 0; j <= ns; ++j) dp[0][j] = 1;
            for (int i = 1; i <= nt; ++i) {
                for (int j = 1; j <= ns; ++j) {
                    dp[i][j] = dp[i][j-1];
                    if (s[j - 1] == t[i - 1]) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
            }
            return dp[nt][ns];
        };
        long long res = ((total - subseqCount(word1, target) - subseqCount(word2, target)) % MOD + MOD) % MOD;
        return static_cast<int>(res);
    }
};

int main()
{
    Solution s;
    assert(s.interleaveCharacters("abc", "bac", "abc") == 5);
    assert(s.interleaveCharacters("cd", "cd", "ccd") == 4);
    assert(s.interleaveCharacters("xy", "xy", "xyxy") == 2);
    assert(s.interleaveCharacters("ab", "cde", "ace") == 1);
    return 0;
}
