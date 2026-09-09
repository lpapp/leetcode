#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n & 3;
    }
};

int main()
{
    Solution s;
    assert(!s.canWinNim(4));
    assert(s.canWinNim(1));
    assert(s.canWinNim(2));
    return 0;
}
