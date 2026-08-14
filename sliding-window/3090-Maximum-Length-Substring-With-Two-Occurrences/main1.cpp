#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int count[26] = {};
        int res = 0;
        for (int l = 0, r = 0, n = s.size(); r < n; ++r) {
            const int c = s[r] - 'a';
            ++count[c];
            while (count[c] > 2) --count[s[l++] - 'a'];
            res = max(res, r - l + 1);
        }
        return res;   
    }
};

int main()
{
    Solution s;
    assert(s.maximumLengthSubstring("bcbbbcba") == 4);
    assert(s.maximumLengthSubstring("aaaa") == 2);
    return 0;
}
