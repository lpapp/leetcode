#include <cassert>

class Solution {
public:
    int maxProduct(int n) {
        int first = 0, second = 0;
        for (; n; n /= 10) {
            int d = n % 10;
            if (d >= first) { second = first; first = d; }
            else if (d > second) second = d;
        }
        return first * second;
    }
};

int main()
{
    Solution s;
    assert(s.maxProduct(31) == 3);
    assert(s.maxProduct(22) == 4);
    assert(s.maxProduct(124) == 8);
    return 0;
}
