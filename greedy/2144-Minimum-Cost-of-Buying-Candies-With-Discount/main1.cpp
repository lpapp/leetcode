#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int res = 0;
        for (int i = 0, n = cost.size(); i < n; res += cost[i], i += 3) if (i + 1 < n) res += cost[i + 1];
        return res;
    }
};

int main()
{
	Solution s;
    vector<int> cost1 = {1, 2, 3};
    assert(s.minimumCost(cost1) == 5);
    vector<int> cost2 = {6, 5, 7, 9, 2, 2};
    assert(s.minimumCost(cost2) == 23);
    vector<int> cost3 = {5, 5};
    assert(s.minimumCost(cost3) == 10);
	return 0;
}
