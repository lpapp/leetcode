#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int threeBack = INT_MAX / 2, twoBack = threeBack, oneBack = 0;
        for (const int cost : costs) {
            const int current = min({threeBack + 9, twoBack + 4, oneBack + 1}) + cost;
            threeBack = twoBack;
            twoBack = oneBack;
            oneBack = current;
        }
        return oneBack;
    }
};

int main()
{
    Solution s;
    vector<int> costs1 = {1, 2, 3, 4};
    assert(s.climbStairs(4, costs1) == 13);
    vector<int> costs2 = {5, 1, 6, 2};
    assert(s.climbStairs(4, costs2) == 11);
    vector<int> costs3 = {9, 8, 3};
    assert(s.climbStairs(3, costs3) == 12);
    return 0;
}
