#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        const int n = items.size();
        vector<int> count(n + 1), multiples(n + 1);
        vector<pair<int, int>> sorted;
        sorted.reserve(n);
        for (const vector<int>& item : items) { ++count[item[0]]; sorted.emplace_back(item[1], item[0]); }
        for (int factor = 1; factor <= n; ++factor) for (int multiple = factor; multiple <= n; multiple += factor) multiples[factor] += count[multiple];
        ranges::sort(sorted);
        const long long cheapest = sorted[0].first;
        long long remaining = budget, res = 0;
        for (const pair<int, int>& item : sorted) {
            const long long price = item.first;
            if (price >= 2 * cheapest || price > remaining) break;
            const long long taken = min<long long>(multiples[item.second] - 1, remaining / price);
            remaining -= taken * price;
            res += 2 * taken;
        }
        return res + remaining / cheapest;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> items1 = {{1, 6}, {2, 4}, {3, 5}};
    assert(s.maximumSaleItems(items1, 19) == 5);
    vector<vector<int>> items2 = {{2, 8}, {1, 10}, {6, 6}, {4, 12}, {5, 20}, {5, 17}};
    assert(s.maximumSaleItems(items2, 35) == 7);
    return 0;
}
