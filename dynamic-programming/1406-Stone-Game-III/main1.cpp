#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        const int n = stoneValue.size();
        int dp0 = 0, dp1 = 0, dp2 = 0;
        for (int i = n - 1; i >= 0; --i) {
            int sum = 0, best = INT_MIN;
            for (int k = 0; k < 3 && i + k < n; ++k) {
                sum += stoneValue[i + k];
                const int next = k == 0 ? dp0 : k == 1 ? dp1 : dp2;
                best = max(best, sum - next);
            }
            dp2 = dp1;
            dp1 = dp0;
            dp0 = best;
        }
        if (dp0 > 0) return "Alice";
        if (dp0 < 0) return "Bob";
        return "Tie";
    }
};

int main()
{
    Solution s;
    vector<int> stoneValue1 = {1, 2, 3, 7};
    assert(s.stoneGameIII(stoneValue1) == "Bob");
    vector<int> stoneValue2 = {1, 2, 3, -9};
    assert(s.stoneGameIII(stoneValue2) == "Alice");
    vector<int> stoneValue3 = {1, 2, 3, 6};
    assert(s.stoneGameIII(stoneValue3) == "Tie");
    return 0;
}
