#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int last[3] = {-1, -1, -1}, res = 0;
        for (int i = 0, n = s.size(); i < n; ++i) { last[s[i] - 'a'] = i; res += ranges::min(last) + 1; }
        return res;
    }
};

int main()
{
    Solution s;
    assert(s.numberOfSubstrings("abcabc") == 10);
    assert(s.numberOfSubstrings("aaacb") == 3);
    assert(s.numberOfSubstrings("abc") == 1);
    return 0;
}
