#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Runtime Complexity: O(N) - The max is calculated at each house once.
// Space complexity:   O(N) - Caching the max value at each house.
// N: number of houses.

int rob(vector<int>& nums) {
  std::size_t snums = nums.size();
  std::vector<int> dp(snums + 1, 0);
  dp[1] = nums.front();
  
  for (std::size_t i = 1; i < snums; ++i) 
    dp[i + 1] = std::max(nums[i] + dp[i - 1], dp[i]);
  
  return dp[snums];
}

int main()
{
  std::vector<int> i1{1, 2, 3, 1};
  std::cout << rob(i1) << std::endl;

  std::vector<int> i2{2, 7, 9, 3, 1};
  std::cout << rob(i2) << std::endl;

  return 0;
}
