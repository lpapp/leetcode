#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[26] = {}, mx = 0, l = 0, n = s.size();
        for (int r = 0; r < n; ++r) { mx = max(mx, ++cnt[s[r] - 'A']); if (r - l + 1 - mx > k) --cnt[s[l++] - 'A']; }
        return n - l;   
    }
};

int main()
{
    Solution s;
    assert(s.characterReplacement("ABAB", 2) == 4);
    assert(s.characterReplacement("AABABBA", 1) == 4);
    return 0;
}
