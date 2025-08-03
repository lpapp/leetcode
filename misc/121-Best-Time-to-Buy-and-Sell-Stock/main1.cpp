#include <algorithm>
#include <iostream>
#include <vector>

// Runtime complexity: O(N ^ 2)
// Space complexity: O(1)
// N: The number of days

using namespace std;

int maxProfit(vector<int>& prices) {
  const std::size_t sprices = prices.size();
  int result = 0;
  
  // Explore all possible ways to buy and sell stock
  for (std::size_t i = 0; i < sprices - 1; ++i) {
    for (std::size_t j = i + 1; j < sprices; ++j) {
      result = std::max(result, prices[j] - prices[i]);
    }
  }

  return result;
}

int main() {
  std::vector<int> i1{7, 1, 5, 3, 6, 4};
  std::cout << maxProfit(i1) << std::endl;

  std::vector<int> i2{7, 6, 4, 3, 1};
  std::cout << maxProfit(i2) << std::endl;

  return 0;
}
