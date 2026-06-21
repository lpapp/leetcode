#include <cassert>
#include <cmath>

class Solution {
public:
    int arrangeCoins(int n) {
        return (int)((-1.0 + sqrt(1.0 + 8.0 * n)) / 2.0);       
    }
};

int main()
{
	Solution s;
    assert(s.arrangeCoins(5) == 2);
    assert(s.arrangeCoins(8) == 3);
	return 0;
}
