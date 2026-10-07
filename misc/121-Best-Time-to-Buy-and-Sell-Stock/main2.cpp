#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int minimumPrice = prices.front(); const int price : prices) { minimumPrice = std::min(minimumPrice, price); result = max(result, price - minimumPrice); }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    assert(solution.maxProfit(prices1) == 5);
    vector<int> prices2 = {7, 6, 4, 3, 1};
    assert(solution.maxProfit(prices2) == 0);
    return 0;
}
