#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int res = 0;
        for (int i = 1, n = s.size(); i < n; i += 2) res += s[i] != s[i - 1];
        return res;
    }
};

int main()
{
    Solution s;
    assert(s.minChanges("1001") == 2);
    assert(s.minChanges("10") == 1);
    assert(s.minChanges("0000") == 0);
    return 0;
}
