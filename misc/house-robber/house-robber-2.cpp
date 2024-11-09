#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Runtime Complexity: O(N) - The max is calculated at each house once.
// Space complexity:   O(N) - N recursion and each recursion occupies one stack space and also for the memoization cache.
// N: number of houses.

int robRecursive(const std::vector<int>& nums, int index, std::vector<int>& memo) {
   // Base case, no houses left, so nothing further to rob.
   if (index < 0) return 0;
  
   // Last house left - do not skip it, but rob it to achieve max.
   if (!index) return nums.front();

   // Look up as already calculated.
   const int memo_index = index + 1;
   if (memo[memo_index] != -1) return memo[memo_index];

   // Rob the current house and skip the next one.
   int rob = nums[index] + robRecursive(nums, index - 2, memo);
   int skip = robRecursive(nums, index - 1, memo);

   // Memoize the calculation.
   memo[memo_index] = std::max(rob, skip);
   return memo[memo_index];
}

int rob(vector<int>& nums) {
  std::size_t snums = nums.size();
  std::vector<int> memo(snums + 1, -1);
  return robRecursive(nums, snums - 1, memo);
}

int main()
{
    std::vector<int> i1{1, 2, 3, 1};
    std::cout << rob(i1) << std::endl;

    std::vector<int> i2{2, 7, 9, 3, 1};
    std::cout << rob(i2) << std::endl;

    return 0;
}
