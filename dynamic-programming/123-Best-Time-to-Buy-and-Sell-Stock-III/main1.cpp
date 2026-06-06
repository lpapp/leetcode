#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy = -prices[0], firstSell = 0, secondBuy = -prices[0], secondSell = 0;
        for (int i = 1, n = prices.size(); i < n; ++i) {
            firstBuy = max(firstBuy, -prices[i]);
            firstSell = max(firstSell, firstBuy + prices[i]);
            secondBuy = max(secondBuy, firstSell - prices[i]);
            secondSell = max(secondSell, secondBuy + prices[i]);
        }
        return secondSell;       
    }
};

int main()
{
	Solution s;
	vector<int> prices1 = {3, 3, 5, 0, 0, 3, 1, 4};
	assert(s.maxProfit(prices1) == 6);
	vector<int> prices2 = {1, 2, 3, 4, 5};
	assert(s.maxProfit(prices2) == 4);
	vector<int> prices3 = {7, 6, 4, 3, 1};
	assert(!s.maxProfit(prices3));
	return 0;
}
