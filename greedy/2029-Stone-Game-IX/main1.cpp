#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c[3] = {};
        for (const int stone : stones) ++c[stone % 3];
        if (!(c[0] & 1)) return c[1] >= 1 && c[2] >= 1;
        return abs(c[1] - c[2]) > 2;   
    }
};

int main()
{
    Solution s;
    vector<int> stones1 = {2, 1};
    assert(s.stoneGameIX(stones1));
    vector<int> stones2 = {2};
    assert(!s.stoneGameIX(stones2));
    vector<int> stones3 = {5, 1, 2, 4, 3};
    assert(!s.stoneGameIX(stones3));
    return 0;
}
