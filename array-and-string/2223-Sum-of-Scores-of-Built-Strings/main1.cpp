#include <cassert>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    long long sumScores(string s) {
        const int n = s.size();
        vector<int> z(n); z[0] = n;
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i < r) z[i] = min(r - i, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
            if (i + z[i] > r) { l = i; r = i + z[i]; }
        }
        return reduce(z.cbegin(), z.cend(), 0LL);
    }
};

int main()
{
    Solution s;
    assert(s.sumScores("babab") == 9);
    assert(s.sumScores("azbazbzaz") == 14);
    return 0;
}
