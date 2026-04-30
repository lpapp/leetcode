#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> validElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffMax(n);
        suffMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i)
            suffMax[i] = max(nums[i], suffMax[i + 1]);

        vector<int> res;
        int prefMax = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || i == n - 1 ||
                nums[i] > prefMax ||
                nums[i] > suffMax[i + 1])
                res.push_back(nums[i]);
            prefMax = max(prefMax, nums[i]);
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Leetcode example 1
    {
        vector<int> nums = {1, 2, 4, 2, 3, 2};
        assert((sol.validElements(nums) == vector<int>{1, 2, 4, 3, 2}));
    }
    // Leetcode example 2
    {
        vector<int> nums = {5, 5, 5, 5};
        assert((sol.validElements(nums) == vector<int>{5, 5}));
    }
    // Leetcode example 3
    {
        vector<int> nums = {1};
        assert((sol.validElements(nums) == vector<int>{1}));
    }
    // Non-monotonic left-valid: 7 > all of {4,1} despite dip at index 1
    {
        vector<int> nums = {4, 1, 7, 7};
        assert((sol.validElements(nums) == vector<int>{4, 7, 7}));
    }
    // Min size > 1: both elements always valid
    {
        vector<int> nums = {3, 1};
        assert((sol.validElements(nums) == vector<int>{3, 1}));
    }
    // Fully increasing: all left-valid
    {
        vector<int> nums = {1, 2, 3, 4, 5};
        assert((sol.validElements(nums) == vector<int>{1, 2, 3, 4, 5}));
    }
    // Fully decreasing: all right-valid
    {
        vector<int> nums = {5, 4, 3, 2, 1};
        assert((sol.validElements(nums) == vector<int>{5, 4, 3, 2, 1}));
    }
    // All equal: only first and last
    {
        vector<int> nums = {7, 7, 7};
        assert((sol.validElements(nums) == vector<int>{7, 7}));
    }
    // Valley: middle element invalid from both directions
    {
        vector<int> nums = {3, 1, 3};
        assert((sol.validElements(nums) == vector<int>{3, 3}));
    }
    // Peak: middle valid from both directions
    {
        vector<int> nums = {1, 5, 1};
        assert((sol.validElements(nums) == vector<int>{1, 5, 1}));
    }
    // Left-valid element after a dip (not a monotonic prefix)
    {
        vector<int> nums = {2, 1, 3, 1};
        assert((sol.validElements(nums) == vector<int>{2, 3, 1}));
    }

    cout << "All tests passed!" << endl;
    return 0;
}
