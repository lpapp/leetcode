#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// Time complexity: O(N)
// Space complexity: O(1)
// N: array length

class Solution {
public:
    int jump(vector<int>& nums) {
        const int snums = nums.size();
        if (snums == 1) return 0;
        
        // Note: this algorithm does not handle the case when we cannot reach
        // the end.
        int max_i = nums.front();
        int remaining_steps = nums.front();
        int min_jumps = 0;
        for (int i = 1, last_i = snums - 1; i < last_i; ++i) {
            max_i = std::max(max_i, i + nums[i]);
            if (!--remaining_steps) {
                ++min_jumps;
                remaining_steps = max_i - i;
            }
        }
        
        return ++min_jumps;
    }
};

int main() {
    Solution solution;
    vector<int> i1{2, 3, 1, 1, 4};
    cout << solution.jump(i1) << endl;

    vector<int> i2{2, 3, 0, 1, 4};
    cout << solution.jump(i2) << endl;

    vector<int> i3{1, 1, 3, 0, 1, 4};
    cout << jump(i3) << endl;

    return 0;
}
