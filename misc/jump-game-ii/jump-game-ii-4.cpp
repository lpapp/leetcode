#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// Time complexity: O(N)
// Space complexity: O(1)
// N: array length

int jump(vector<int>& nums) {
  const int snums = nums.size();
  const int last_i = snums - 1;
  if (snums <= 1)
    return 0;
  
  int max_i = nums.front();
  if (max_i >= last_i)
    return 1;
  
  if (!max_i)
    return -1;
  
  int remaining_steps = max_i;
  int min_jumps = 1;
  
  // 1, 1, 3, 0, 1, 4 -> last_i = 5, max_i = 1, remaining_steps = 1
  // i = 1, curr_max_i = 2, max_i = 2, min_jumps = 2
  for (int i = 1; i < snums; ++i) {
    // Arrived at the last index
    if (i == last_i)
      return min_jumps;
  
    const int curr_max_i = i + nums[i];

    // If the jump can be made to the end from the current index, jump the last
    // one to get there.
    if (curr_max_i >= last_i)
      return min_jumps + 1;

    // Update the max index to which one can jump.
    max_i = std::max(max_i, curr_max_i);
  
    // Use a step from the current jump amount
    if (!--remaining_steps) {
	// if no steps left from the current jump amount, we have used all the
	// steps and therefore jumped.
    	++min_jumps;
    
	// If the current index is the max index to reach from previous indexes
	// and the current index has value 0 for jump, there is no solution.
    	if (i >= max_i)
    	  return -1;
    
        // Calculate the number of remaining steps in the current jump
    	remaining_steps = max_i - i;
    }
  }
  
  return -1;
}

int main() {
  vector<int> i1{2, 3, 1, 1, 4};
  std::cout << jump(i1) << std::endl;

  vector<int> i2{2, 3, 0, 1, 4};
  std::cout << jump(i2) << std::endl;

  vector<int> i3{1, 1, 3, 0, 1, 4};
  std::cout << jump(i3) << std::endl;

  return 0;
}
