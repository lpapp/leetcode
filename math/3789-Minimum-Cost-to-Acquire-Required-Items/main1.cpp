#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        const long long low = min(need1, need2), high = max(need1, need2);
        return min({1LL * cost1 * need1 + 1LL * cost2 * need2, high * costBoth, low * costBoth + (need1 - low) * cost1 + (need2 - low) * cost2});        
    }
};

int main()
{
    Solution s;
    assert(s.minimumCost(3, 2, 1, 3, 2) == 3);
    assert(s.minimumCost(5, 4, 15, 2, 3) == 22);
    assert(s.minimumCost(5, 4, 15, 0, 0) == 0);
    return 0;
}
