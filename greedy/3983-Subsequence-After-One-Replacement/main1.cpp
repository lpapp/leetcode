#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        const int n = s.size(), m = t.size();
        vector<int> left(n + 1, m + 1); left[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (left[i] > m) break;
            int j = left[i];
            while (j < m && t[j] != s[i]) ++j;
            if (j < m) left[i + 1] = j + 1;
        }
        vector<int> right(n + 1, -1); right[n] = m;
        for (int i = n - 1; i >=0; --i) {
            if (right[i + 1] < 0) break;
            int j = right[i + 1] - 1;
            while (j >= 0 && t[j] != s[i]) --j;
            right[i] = j;
        }
        if (left[n] <= m) return true;
        for (int k = 0; k < n; ++k) {
            if (left[k] > m) break;
            if (right[k + 1] >= 0 && left[k] < right[k + 1]) return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    assert(s.canMakeSubsequence("cat", "chat"));
    assert(!s.canMakeSubsequence("plane", "apple"));
    return 0;
}
