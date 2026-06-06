#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int n = prices.size();
        if (!n || !k) return 0;
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; ++i) profit += max(0, prices[i] - prices[i - 1]);
            return profit;
        }
        vector<int> buy(k + 1, numeric_limits<int>::min()), sell(k + 1, 0);
        for (int price : prices) {
            for (int j = 1; j <= k; ++j) {
                buy[j] = max(buy[j], sell[j - 1] - price);
                sell[j] = max(sell[j], buy[j] + price);
            }
		}
        return sell[k];
    }
};

int main()
{
	Solution s;
	vector<int> prices1 = {2, 4, 1};
	assert(s.maxProfit(2, prices1) == 2);
	vector<int> prices2 = {3, 2, 6, 5, 0, 3};
	assert(s.maxProfit(2, prices2) == 7);
	return 0;
}
