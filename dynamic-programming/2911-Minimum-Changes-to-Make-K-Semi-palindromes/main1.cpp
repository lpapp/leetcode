#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumChanges(string s, int k) {
        const int n = s.size();
        constexpr int INF = 1'000'000'000;
        vector<vector<int>> divs(n + 1), g(n, vector<int>(n, INF)), f(k + 1, vector<int>(n + 1, INF));
        for (int d = 1; d <= n; ++d) for (int m = 2 * d; m <= n; m += d) divs[m].push_back(d);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                for (const int d : divs[j - i + 1]) {
                    int cnt = 0;
                    for (int r = 0; r < d; ++r)
                        for (int a = i + r, b = j - d + 1 + r; a < b; a += d, b -= d) cnt += s[a] != s[b];
                    g[i][j] = min(g[i][j], cnt);
                }
        f[0][0] = 0;
        for (int j = 1; j <= k; ++j)
            for (int i = 2 * j; i <= n; ++i)
                for (int h = 2 * (j - 1); h <= i - 2; ++h) f[j][i] = min(f[j][i], f[j - 1][h] + g[h][i - 1]);
        return f[k][n];   
    }
};

int main()
{
    Solution s;
    assert(s.minimumChanges("abcac", 2) == 1);
    assert(s.minimumChanges("abcdef", 2) == 2);
    assert(s.minimumChanges("aabbaa", 3) == 0);
    return 0;
}
