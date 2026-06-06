#include <cassert>

class Solution {
public:
    bool consecutiveSetBits(int n) {
        int shifted = n & (n >> 1);
        return shifted && !(shifted & (shifted - 1));
    }
};

int main()
{
    Solution s;
    assert(s.consecutiveSetBits(6));
    assert(!s.consecutiveSetBits(5));
    return 0;
}
