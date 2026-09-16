#include <cassert>
#include <vector>

using namespace std;

class Solution {
    static constexpr int MOD = 1'000'000'007;
public:
    int numberOfSets(int n, int k) {
        vector<long long> f(k + 1), g(k + 1), pf(k + 1), pg(k + 1); pf[0] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                f[j] = (pf[j] + pg[j]) % MOD;
                g[j] = pg[j];
                if (j) g[j] = (g[j] + pf[j - 1] + pg[j - 1]) % MOD;
            }
            swap(f, pf); swap(g, pg);
        }
        return (pf[k] + pg[k]) % MOD;
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
