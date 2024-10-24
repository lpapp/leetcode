#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// Time complexity: O(N ^ N)
// Space complexity: O(N)
// N: array length

std::size_t jumpRecursive(const std::vector<int>& nums, std::size_t start, std::size_t end)
{
  // Base case
  if (start == end)
    return 0;

  // Cannot jump from the current index in the array
  if (!nums[start])
    return std::numeric_limits<size_t>::max();

  // Call the function recursively from each reachable index from the current
  // index in the array, to divide the task into subtasks. Add one to the
  // result for the subtask and maintain the minimum number of jumps.
  std::size_t min_jumps = std::numeric_limits<size_t>::max();
  for (std::size_t i = start + 1; i <= end && i <= start + nums[start]; ++i) {
    const std::size_t jumps = jumpRecursive(nums, i, end);
    if (jumps != std::numeric_limits<size_t>::max())
      min_jumps = std::min(min_jumps, jumps + 1);
  }

  return min_jumps;
}

int jump(vector<int>& nums) {
  return jumpRecursive(nums, 0, nums.size() - 1);
}

int main() {
  vector<int> i1{2, 3, 1, 1, 4};
  std::cout << jump(i1) << std::endl;

  vector<int> i2{2, 3, 0, 1, 4};
  std::cout << jump(i2) << std::endl;
  return 0;
}
