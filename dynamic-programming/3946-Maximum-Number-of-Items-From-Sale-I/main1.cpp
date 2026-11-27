#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int freq[1501] = {}, multiples[1501] = {}, minPrice = INT_MAX;
        vector<int> dp(budget + 1);
        for (const vector<int>& item : items) { ++freq[item[0]]; minPrice = min(minPrice, item[1]); }
        for (int factor = 1; factor <= 1500; ++factor) for (int multiple = factor; multiple <= 1500; multiple += factor) multiples[factor] += freq[multiple];
        for (const vector<int>& item : items) for (int spent = budget; spent >= item[1]; --spent) dp[spent] = max(dp[spent], dp[spent - item[1]] + multiples[item[0]]);
        for (int spent = minPrice; spent <= budget; ++spent) dp[spent] = max(dp[spent], dp[spent - minPrice] + 1);
        return dp[budget];   
    }
};

int main()
{
    Solution s;
    vector<vector<int>> items1 = {{6, 2}, {2, 6}, {3, 4}};
    assert(s.maximumSaleItems(items1, 9) == 4);
    vector<vector<int>> items2 = {{2, 4}, {3, 2}, {4, 1}, {6, 4}, {12, 4}};
    assert(s.maximumSaleItems(items2, 8) == 10);
    return 0;
}
