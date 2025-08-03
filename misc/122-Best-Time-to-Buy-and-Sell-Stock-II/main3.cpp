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
        int result = 0;
        const std::size_t sprices = prices.size();
        // Add profit each day. Ignore if loss or no profit.
        for (std::size_t i = 1; i < sprices; ++i) {
            if (prices[i] > prices[i - 1]) 
              result += prices[i] - prices[i - 1];
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> i1{7, 1, 5, 3, 6, 4};
    cout << solution.maxProfit(i1) << endl;

    vector<int> i2{1, 2, 3, 4, 5};
    cout << solution.maxProfit(i2) << endl;

    vector<int> i3{7, 6, 4, 3, 1};
    cout << solution.maxProfit(i3) << endl;

    return 0;
}
