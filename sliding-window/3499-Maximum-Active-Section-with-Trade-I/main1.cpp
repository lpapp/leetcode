#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int res = 0, mx = 0, pre = INT_MIN;
        for (int i = 0, n = s.size(); i < n;) {
            int j = i + 1;
            while (j < n && s[j] == s[i]) ++j;
            const int cur = j - i;
            if (s[i] == '1') res += cur;
            else { mx = max(mx, pre + cur); pre = cur; }
            i = j;
        }
        return res + mx;
    }
};

int main()
{
    Solution s;
    assert(s.maxActiveSectionsAfterTrade("01") == 1);
    assert(s.maxActiveSectionsAfterTrade("0100") == 4);
    assert(s.maxActiveSectionsAfterTrade("1000100") == 7);
    assert(s.maxActiveSectionsAfterTrade("01010") == 4);
    return 0;
}
