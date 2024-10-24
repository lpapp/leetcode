#include <iostream>
#include <vector>

// Time complexity: O(N)
// Space complexity: O(1)
// N: array length

using namespace std;

bool canJump(vector<int>& nums) {
    for (std::size_t maxReach = 0, i = 0; i < nums.size(); ++i) {
        max_i = max(i + nums[i], max_i);
        if (max_i == i) return false;
    }

    return true;
}

int main()
{
    std::vector<int> i1{2, 3, 1, 1, 4};
    std::cout << canJump(i1) << std::endl;

    std::vector<int> i2{3, 2, 1, 0, 4};
    std::cout << canJump(i2) << std::endl;

    return 0;
}
