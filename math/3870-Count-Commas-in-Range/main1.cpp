#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    int countCommas(int n) {
        return std::max(0, n - 999);
    }
};

int main()
{
    Solution s;
    assert(s.countCommas(1002) == 3);
    assert(s.countCommas(998) == 0);
    return 0;
}
