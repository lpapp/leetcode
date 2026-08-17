#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        const int n = stones.size();
        for (int i = 1; i < n; ++i) stones[i] += stones[i - 1];
        int best = stones[n - 1];
        for (int i = n - 2; i > 0; --i) best = max(best, stones[i] - best);
        return best;
    }
};

int main()
{
    Solution s;
    vector<int> stones1 = {-1, 2, -3, 4, -5};
    assert(s.stoneGameVIII(stones1) == 5);
    vector<int> stones2 = {7, -6, 5, 10, 5, -2, -6};
    assert(s.stoneGameVIII(stones2) == 13);
    vector<int> stones3 = {-10, -12};
    assert(s.stoneGameVIII(stones3) == -22);
    return 0;
}
