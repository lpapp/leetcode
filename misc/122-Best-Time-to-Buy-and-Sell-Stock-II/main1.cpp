#include <algorithm>
#include <iostream>
#include <vector>

// Runtime complexity: O(2 ^ N)
// Space complexity: O(N)
// N: The number of days

using namespace std;

int maxProfitRecursive(const std::vector<int>& price, int start, int end) {
  int result = 0;
  
  // Consider each possible pair, the profit before and after the pair.
  for (int i = start; i < end; ++i) {
    for (int j = i + 1; j <= end; ++j) {
      if (price[j] > price[i]) {
        const int current_profit = (price[j] - price[i]);
        const int previous_profit = maxProfitRecursive(price, start, i - 1);
        const int next_profit = maxProfitRecursive(price, j + 1, end);
        const int all_profit = current_profit + previous_profit + next_profit;
        result = std::max(result, all_profit);
      }
    }
  }

  return result;
}

int maxProfit(vector<int>& prices) {
  return maxProfitRecursive(prices, 0, prices.size() - 1);
}

int main() {
  std::vector<int> i1{7, 1, 5, 3, 6, 4};
  std::cout << maxProfit(i1) << std::endl;

  std::vector<int> i2{1, 2, 3, 4, 5};
  std::cout << maxProfit(i2) << std::endl;

  std::vector<int> i3{7, 6, 4, 3, 1};
  std::cout << maxProfit(i3) << std::endl;

  return 0;
}
