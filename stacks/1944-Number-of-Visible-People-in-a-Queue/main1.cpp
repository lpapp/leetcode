#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        const int n = heights.size();
        vector<int> ans(n), stk;
        for (int i = n - 1; i >= 0; stk.push_back(heights[i--])) {
            for (; !stk.empty() && stk.back() < heights[i]; ++ans[i], stk.pop_back());
            if (!stk.empty()) ++ans[i];
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> heights1 = {10, 6, 8, 5, 11, 9};
    vector<int> res1 = {3, 1, 2, 1, 1, 0};
    assert(s.canSeePersonsCount(heights1) == res1);
    vector<int> heights2 = {5, 1, 2, 3, 10};
    vector<int> res2 = {4, 1, 1, 1, 0};
    assert(s.canSeePersonsCount(heights2) == res2);
    return 0;
}
