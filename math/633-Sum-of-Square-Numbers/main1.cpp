#include <cassert>
#include <cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long l = 0, r = sqrt(c); l <= r;) {
            long sum = l * l + r * r;
            if (sum == c) return true;
            if (sum < c) ++l;
            else --r;
        }
        return false;
    }
};

int main()
{
	Solution s;
    assert(s.judgeSquareSum(5));
    assert(!s.judgeSquareSum(3));
	return 0;
}
