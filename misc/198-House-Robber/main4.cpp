#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

// Runtime Complexity: O(N) - The max is calculated at each house once.
// Space complexity:   O(1) - Caching the max value for the last two houses.
// N: number of houses.

class Solution {
public:
    int rob(vector<int>& nums) {
        size_t snums = nums.size();
        if (!snums) return 0;
        
        int front = nums.front();
        if (snums == 1) return front;
        
        array<int, 2> dp{0, front};
        
        int result;
        for (size_t i = 1; i < snums; ++i) {
            result = max(nums[i] + dp.front(), dp.back());
            dp = {dp.back(), result};
        }
        
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> i1{1, 2, 3, 1};
    cout << solution.rob(i1) << endl;

    vector<int> i2{2, 7, 9, 3, 1};
    cout << solution.rob(i2) << endl;

    return 0;
}
