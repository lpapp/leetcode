#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// Time complexity: O(N ^ 2)
// Space complexity: O(N)
// N: array length

int jumpRecursive(const std::vector<int>& nums, int start, int end, std::vector<int>& memo)
{
  // Base case
  if (start == end)
    return 0;

  if (memo[start] != -1)
    return memo[start];

  // Cannot jump from the current index in the array
  if (!nums[start])
    return std::numeric_limits<int>::max();

  // Call the function recursively from each reachable index from the current
  // index in the array, to divide the task into subtasks. Add one to the
  // result for the subtask and maintain the minimum number of jumps.
  int min_jumps = std::numeric_limits<int>::max();
  for (int i = start + 1; i <= end && i <= start + nums[start]; ++i) {
    const int jumps = jumpRecursive(nums, i, end, memo);
    if (jumps != std::numeric_limits<int>::max())
      min_jumps = std::min(min_jumps, jumps + 1);
  }

  memo[start] = min_jumps;
  return memo[start];
}

int jump(vector<int>& nums) {
  std::vector<int> memo(nums.size(), -1);
  return jumpRecursive(nums, 0, nums.size() - 1, memo);
}

int main() {
  vector<int> i1{2, 3, 1, 1, 4};
  std::cout << jump(i1) << std::endl;

  vector<int> i2{2, 3, 0, 1, 4};
  std::cout << jump(i2) << std::endl;
  return 0;
}
