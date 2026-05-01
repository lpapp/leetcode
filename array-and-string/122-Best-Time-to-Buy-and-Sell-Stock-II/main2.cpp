#include <algorithm>
#include <iostream>
#include <vector>

// Runtime complexity: O(N)
// Space complexity: O(1)
// N: The number of days

using namespace std;

int maxProfit(vector<int>& prices) {
  const int last_index = prices.size() - 1;
  int localMinimum = prices.front();
  int localMaximum = prices.front();
  int result = 0;
  
  // Add the current profit after each local minimum and maximum
  for (int i = 0; i < last_index; localMaximum = prices[i], result += localMaximum - localMinimum) {
    // Find the local minimum
    for (; i < last_index && prices[i] >= prices[i + 1]; ++i);
    
    // Find the local maximum
    for (localMinimum = prices[i]; i < last_index && prices[i] <= prices[i + 1]; ++i);
  }
  
  return result;
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
