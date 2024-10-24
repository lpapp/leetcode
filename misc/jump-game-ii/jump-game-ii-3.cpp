#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// Time complexity: O(N ^ 2)
// Space complexity: O(N)
// N: array length

int jump(vector<int>& nums) {
  const std::size_t snums = nums.size();

  // jumps[i] is the minimum numbers of jumps from nums[0] to nums[i]
  vector<int> jumps(snums, std::numeric_limits<int>::max());
  
  if (!snums || !nums[0])
    return std::numeric_limits<int>::max();

  jumps.front() = 0;
  for (std::size_t i = 1; i < snums; ++i) {
    for (std::size_t j = 0; j < i; ++j) {
      if (i <= j + nums[j] && jumps[j] != std::numeric_limits<int>::max()) {
        jumps[i] = std::min(jumps[i], jumps[j] + 1);
        break;
      }
    }
  }
  return jumps.back();
}

int main() {
  vector<int> i1{2, 3, 1, 1, 4};
  std::cout << jump(i1) << std::endl;

  vector<int> i2{2, 3, 0, 1, 4};
  std::cout << jump(i2) << std::endl;
  return 0;
}
