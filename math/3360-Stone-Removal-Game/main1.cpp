#include <cassert>

class Solution {
public:
    bool canAliceWin(int n) { return n >= 10 && n < 19 || n >= 27 && n < 34 || n >= 40 && n < 45 || n >= 49 && n < 52; }       
};

int main()
{
    Solution s;
    assert(s.canAliceWin(12));
    assert(!s.canAliceWin(1));
    return 0;
}
