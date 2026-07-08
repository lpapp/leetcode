#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1'000'000'007, n = s.size();
        vector<int> pos;
        for (int i = 0; i < n; ++i) if (s[i] != '0') pos.push_back(i);
        const int k = pos.size();
        vector<long long> P(k + 1), pow10(k + 1), dsum(k + 1); pow10[0] = 1;
        for (int i = 0; i < k; ++i) { const int d = s[pos[i]] - '0'; P[i + 1] = (P[i] * 10 + d) % MOD; pow10[i + 1] = pow10[i] * 10 % MOD; dsum[i + 1] = dsum[i] + d; }
        vector<int> res; res.reserve(queries.size());
        for (const vector<int>& q : queries) {
            const int l = q[0], r = q[1], a = int(lower_bound(pos.begin(), pos.end(), l) - pos.begin()), b = int(upper_bound(pos.begin(), pos.end(), r) - pos.begin()) - 1;
            if (a > b) { res.push_back(0); continue; }
            const int len = b - a + 1;
            const long long x = (P[b + 1] - P[a] * pow10[len] % MOD + MOD) % MOD, sum = dsum[b + 1] - dsum[a];
            res.push_back(int(x * (sum % MOD) % MOD));
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> queries1 = {{0, 7}, {1, 3}, {4, 6}};
    vector<int> res1 = {12340, 4, 9};
    assert(s.sumAndMultiply("10203004", queries1) == res1);

    vector<vector<int>> queries2 = {{0, 3}, {1, 1}};
    vector<int> res2 = {1, 0};
    assert(s.sumAndMultiply("1000", queries2) == res2);

    vector<vector<int>> queries3 = {{0, 9}};
    vector<int> res3 = {444444137};
    assert(s.sumAndMultiply("9876543210", queries3) == res3);
    return 0;
}
