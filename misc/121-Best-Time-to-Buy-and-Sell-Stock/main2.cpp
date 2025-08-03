#include <algorithm>
#include <iostream>
#include <vector>

// Runtime complexity: O(N)
// Space complexity: O(1)
// N: The number of days

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimumPrice = prices.front();
        int result = 0;
 
        // Update the max profit if the difference between the current price and the
        // minimum seen so far is greater the maximum profit seen so far.
        for (const int price : prices) {
            minimumPrice = std::min(minimumPrice, price);
            result = max(result, price - minimumPrice);
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> i1{7, 1, 5, 3, 6, 4};
    cout << solution.maxProfit(i1) << endl;

    vector<int> i2{7, 6, 4, 3, 1};
    cout << solution.maxProfit(i2) << endl;

    return 0;
}
