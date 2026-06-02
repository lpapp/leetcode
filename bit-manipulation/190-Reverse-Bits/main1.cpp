#include <cassert>

class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        for (int i = 0; i < 32 && n; n >>= 1, ++i) res |= (n & 1) << (31 - i);
        return res;
    }
};

int main()
{
    Solution s;
    assert(s.reverseBits(43261596) == 964176192);
    assert(s.reverseBits(2147483644) == 1073741822);
    return 0;
}
