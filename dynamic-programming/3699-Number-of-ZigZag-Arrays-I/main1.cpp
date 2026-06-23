#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
    	const int MOD = 1'000'000'007, m = r - l + 1;
    	vector<long> up(m), down(m);
    	for (int j = 0; j < m; ++j) { down[j] = j; up[j] = m - 1 - j; }
    	for (int i = 3; i <= n; ++i) {
    	    vector<long> next_up(m), next_down(m);
    	    long prefix = 0;
  			for (int y = 0; y < m; ++y) { next_down[y] = prefix % MOD; prefix += up[y]; }
            long suffix = 0;
  			for (int y = m - 1; y >= 0; --y) { next_up[y] = suffix % MOD; suffix += down[y]; }
  
            up = std::move(next_up), down = std::move(next_down);
        }
        long res = 0;
        for (int j = 0; j < m; ++j) res = (res + up[j] + down[j]) % MOD;
        return res;
    }
};

int main()
{
    Solution s;
    assert(s.zigZagArrays(3, 4, 5) == 2);
    assert(s.zigZagArrays(3, 1, 3) == 10);
    return 0;
}
