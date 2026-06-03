#include <cassert>

class Solution {
public:
    int trailingZeroes(int n) {
         int res;
        for (res = 0; n > 0; n /= 5, res += n);
        return res;
    }
};

int main()
{
	Solution s;
    assert(!s.trailingZeroes(3));
    assert(s.trailingZeroes(5) == 1);
    assert(!s.trailingZeroes(0));
	return 0;
}
