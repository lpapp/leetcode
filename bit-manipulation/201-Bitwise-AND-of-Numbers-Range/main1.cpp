#include <cassert>

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right) right &= (right - 1);
        return right;
    }
};

int main()
{
    Solution s;
    assert(s.rangeBitwiseAnd(5, 7) == 4);
    assert(!s.rangeBitwiseAnd(0, 0));
    assert(!s.rangeBitwiseAnd(1, 2147483647));
    return 0;
}
