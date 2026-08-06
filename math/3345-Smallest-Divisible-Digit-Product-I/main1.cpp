#include <cassert>

class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n; ; ++i) {
            int p = 1;
            for (int x = i; x; x /= 10) {
                if (!(x % 10)) { p = 0; break; }
                p *= x % 10;
            }
            if (!(p % t)) return i;
        } 
    }
};

int main()
{
    Solution s;
    assert(s.smallestNumber(10, 2) == 10);
    assert(s.smallestNumber(15, 3) == 16);
    return 0;
}
