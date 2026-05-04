#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n - 2 && nums[i] <= 0; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) ++j;
                else if (sum > 0) --k;
                else {
                    res.push_back({nums[i], nums[j++], nums[k--]});
                    while (j < k && nums[j] == nums[j - 1]) ++j;
                    while (j < k && nums[k] == nums[k + 1]) --k;
                }
            }
        }
        return res;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
	vector<vector<int>> res1 = {{-1, -1, 2}, {-1, 0, 1}};
    assert(s.threeSum(nums1) == res1);
    vector<int> nums2 = {0, 1, 1};
	vector<vector<int>> res2 = {};
    assert(s.threeSum(nums2) == res2);
    vector<int> nums3 = {0, 0, 0};
	vector<vector<int>> res3 = {{0, 0, 0}};
    assert(s.threeSum(nums3) == res3);
	return 0;
}
