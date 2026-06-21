#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int hash[100001] = {};
        for (const int cost : costs) ++hash[cost];
        int res = 0;
        for (int cost = 1; cost <= 100000 && coins >= cost; ++cost) { const int buy = min(hash[cost], coins / cost); res += buy; coins -= buy * cost; }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> costs1 = {1, 3, 2, 4, 1};
    assert(s.maxIceCream(costs1, 7) == 4);
    vector<int> costs2 = {10, 6, 8, 7, 7, 8};
    assert(!s.maxIceCream(costs2, 5));
    vector<int> costs3 = {1, 6, 3, 1, 2, 5};
    assert(s.maxIceCream(costs3, 20) == 6);
    return 0;
}
