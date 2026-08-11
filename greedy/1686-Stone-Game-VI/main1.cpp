#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        const int n = aliceValues.size();
        vector<vector<int>> buckets(201);
        for (int i = 0; i < n; ++i) buckets[aliceValues[i] + bobValues[i]].push_back(i);
        int a = 0, b = 0;
        for (int v = 200, turn = 0; v >= 2; --v)
            for (const int idx : buckets[v]) {
                if (!(turn & 1)) a += aliceValues[idx];
                else b += bobValues[idx];
                ++turn;
            }
        return a > b ? 1 : (a < b ? -1 : 0);
    }
};

int main()
{
    Solution s;
    vector<int> aliceValues1 = {1, 3};
    vector<int> bobValues1 = {2, 1};
    assert(s.stoneGameVI(aliceValues1, bobValues1) == 1);
    vector<int> aliceValues2 = {1, 2};
    vector<int> bobValues2 = {3, 1};
    assert(!s.stoneGameVI(aliceValues2, bobValues2));
    vector<int> aliceValues3 = {2, 4, 3};
    vector<int> bobValues3 = {1, 6, 7};
    assert(s.stoneGameVI(aliceValues3, bobValues3) == -1);
    return 0;
}
