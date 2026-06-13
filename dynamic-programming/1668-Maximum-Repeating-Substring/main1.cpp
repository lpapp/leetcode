#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        const int n = sequence.size(), m = word.size();
        vector<int> fail(m, 0);
        for (int i = 1, j = 0; i < m; ++i) {
            while (j && word[j] != word[i]) j = fail[j - 1];
            if (word[j] == word[i]) ++j;
            fail[i] = j;
        }
        vector<int> dp(n, 0);
        int ans = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j && word[j] != sequence[i]) j = fail[j - 1];
            if (word[j] == sequence[i]) ++j;
            if (j == m) {
                dp[i] = 1 + (i >= m ? dp[i - m] : 0);
                ans = max(ans, dp[i]);
                j = fail[j - 1];
            }
        }
        return ans;     
    }
};

int main()
{
    Solution s;
    assert(s.maxRepeating("ababc", "ab") == 2);
    assert(s.maxRepeating("ababc", "ba") == 1);
    assert(!s.maxRepeating("ababc", "ac"));
    return 0;
}
