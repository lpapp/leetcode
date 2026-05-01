#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (size_t i = 1; i < prices.size(); ++i) res += max(0, prices[i] - prices[i - 1]);
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> i1{7, 1, 5, 3, 6, 4};
    assert(solution.maxProfit(i1) == 7);
    vector<int> i2{1, 2, 3, 4, 5};
    assert(solution.maxProfit(i2) == 4);
    vector<int> i3{7, 6, 4, 3, 1};
    assert(!solution.maxProfit(i3));
    return 0;
}
