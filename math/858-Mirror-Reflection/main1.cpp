#include <cassert>

class Solution {
public:
    int mirrorReflection(int p, int q) {
        while (!(p & 1) && !(q & 1)) { p >>= 1; q >>= 1; }
        if (p & 1 && q & 1) return 1;
        return q & 1 ? 2 : 0;
    }
};

int main()
{
    Solution s;
    assert(s.mirrorReflection(2, 1) == 2);
    assert(s.mirrorReflection(3, 1) == 1);
    assert(s.mirrorReflection(6, 4) == 0);
    return 0;
}
