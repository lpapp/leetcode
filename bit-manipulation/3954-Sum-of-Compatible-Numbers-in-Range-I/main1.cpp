#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int res = 0;
        for (int x = max(1, n - k); x <= (n + k); ++x) {
            if (!(n & x)) res += x;
        }
        return res;
    }
};

int main()
{
    Solution s;
    assert(s.sumOfGoodIntegers(2, 3) == 10);
    assert(!s.sumOfGoodIntegers(5, 1));
    return 0;
}
