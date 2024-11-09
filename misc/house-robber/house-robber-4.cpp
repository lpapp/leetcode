#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

// Runtime Complexity: O(N) - The max is calculated at each house once.
// Space complexity:   O(1) - Caching the max value for the last two houses.
// N: number of houses.

int rob(vector<int>& nums) {
  std::size_t snums = nums.size();
  if (!snums)
    return 0;

  int front = nums.front();
  if (snums == 1)
    return front;

  std::array<int, 2> dp{0, front};

  int result;
  for (std::size_t i = 1; i < snums; ++i) {
    result = std::max(nums[i] + dp.front(), dp.back());
    dp = {dp.back(), result};
  }

  return result;
}

int main()
{
    std::vector<int> i1{1, 2, 3, 1};
    std::cout << rob(i1) << std::endl;

    std::vector<int> i2{2, 7, 9, 3, 1};
    std::cout << rob(i2) << std::endl;

    return 0;
}
