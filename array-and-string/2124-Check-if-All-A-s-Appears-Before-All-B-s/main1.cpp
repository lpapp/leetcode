#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    bool checkString(string s) {
        return ranges::is_sorted(s);
    }
};

int main()
{
    Solution s;
    assert(s.checkString("aaabbb"));
    assert(!s.checkString("abab"));
    assert(s.checkString("bbb"));
    return 0;
}
