#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int res = 0;
        for (int center = 0, n = s.size(), start = 0; center < 2 * n - 1; ++center) { for (int l = center / 2, r = l + (center & 1); l >= start && r < n && s[l] == s[r]; --l, ++r) { if (r - l + 1 >= k) { ++res; start = r + 1; break; } } }
        return res;
    }
};

int main()
{
    Solution s;
    assert(s.maxPalindromes("abaccdbbd", 3) == 2);
    assert(s.maxPalindromes("adbcda", 2) == 0);
    return 0;
}
