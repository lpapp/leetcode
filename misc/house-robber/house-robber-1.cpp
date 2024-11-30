#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Runtime Complexity: O(2^N) - either rob or skip a house recursively
// Space complexity:   O(N)   - N recursion and each recursion occupies one stack space
// N: number of houses

int robRecursive(const std::vector<int>& nums, int index) {
   // Base case, no houses left, so nothing further to rob.
   if (index < 0)
     return 0;
  
   // Last house left - do not skip it, but rob it to achieve max.
   if (!index)
     return nums.front();

   // Rob the current house and skip the next one
   int rob = nums[index] + robRecursive(nums, index - 2);
   int skip = robRecursive(nums, index - 1);

   return std::max(rob, skip);
}

int rob(vector<int>& nums) {
  return robRecursive(nums, nums.size());
}

int main()
{
  std::vector<int> i1{1, 2, 3, 1};
  std::cout << rob(i1) << std::endl;

  std::vector<int> i2{2, 7, 9, 3, 1};
  std::cout << rob(i2) << std::endl;

  return 0;
}
