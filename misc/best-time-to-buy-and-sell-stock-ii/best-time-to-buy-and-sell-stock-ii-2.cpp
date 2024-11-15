#include <algorithm>
#include <iostream>
#include <vector>

// Runtime complexity: O(N)
// Space complexity: O(1)
// N: The number of days

using namespace std;

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

int main() {
  std::vector<int> i1{7, 1, 5, 3, 6, 4};
  std::cout << maxProfit(i1) << std::endl;

  std::vector<int> i2{7, 6, 4, 3, 1};
  std::cout << maxProfit(i2) << std::endl;

  return 0;
}
