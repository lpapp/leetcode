#include <cassert>
#include <bit>

using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        return popcount(static_cast<unsigned>(n));
    }
};

int main()
{
    Solution s;
    assert(s.hammingWeight(11) == 3);
    assert(s.hammingWeight(128) == 1);
    assert(s.hammingWeight(2147483645) == 30);
    return 0;
}
