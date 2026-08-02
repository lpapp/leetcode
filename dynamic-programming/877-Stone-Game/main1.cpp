#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) { return true; }
};

int main()
{
    Solution s;
    vector<int> piles1 = {5, 3, 4, 5};
    assert(s.stoneGame(piles1));
    vector<int> piles2 = {3, 7, 2, 3};
    assert(s.stoneGame(piles2));
    return 0;
}
