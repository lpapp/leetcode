#include <algorithm>
#include <iostream>
#include <vector>

// Time complexity: O(N)
// Space complexity: O(1)
// N: array length

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        for (size_t max_i = 0, i = 0; i < nums.size(); ++i) {
            if (max_i < i) return false;
            const size_t num = nums[i];
            max_i = max(i + num, max_i);
        }

        return true;
    }
};

int main()
{
    Solution solution;
    vector<int> i1{2, 3, 1, 1, 4};
    cout << solution.canJump(i1) << endl;

    vector<int> i2{3, 2, 1, 0, 4};
    cout << solution.canJump(i2) << endl;

    vector<int> i3{0};
    cout << solution.canJump(i3) << endl;

    return 0;
}
