#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        for (long long boundary = 1000; boundary <= n; boundary = boundary > n / 1000 ? n + 1 : boundary * 1000) total += n - boundary + 1;
        return total;       
    }
};

int main()
{
    Solution s;
    assert(s.countCommas(1002) == 3);
    assert(s.countCommas(998) == 0);
    return 0;
}
