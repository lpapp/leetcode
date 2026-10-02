#include <cassert>
#include <numeric>

using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int g = std::gcd(p, q);
        p = (p / g) % 2;
        q = (q / g) % 2;
        if (p == 1 && q == 1) return 1;
        return p == 1 ? 0 : 2;
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
