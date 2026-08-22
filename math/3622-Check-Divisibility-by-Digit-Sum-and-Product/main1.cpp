#include <cassert>

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1;
        for (int m = n; m; m /= 10) { const int d = m % 10; sum += d; prod *= d; }
        return n % (sum + prod) == 0;
    }
};

int main()
{
    Solution s;
    assert(s.checkDivisibility(99));
    assert(!s.checkDivisibility(23));
    return 0;
}
