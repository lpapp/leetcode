#include <iostream>
#include <vector>

// Greedy algorithm
// Time complexity: O(N)
// Space complexity: O(1)
// N: array length

using namespace std;

bool canJump(vector<int>& nums) {
    int jump = nums.size() - 1;
    for (int i = jump - 1; i >= 0; --i) {
        if (i + nums[i] >= jump) {
            jump = i;
        }
    }

    return !jump;
}

int main()
{
    std::vector<int> i1{2, 3, 1, 1, 4};
    std::cout << canJump(i1) << std::endl;

    std::vector<int> i2{3, 2, 1, 0, 4};
    std::cout << canJump(i2) << std::endl;

    return 0;
}
