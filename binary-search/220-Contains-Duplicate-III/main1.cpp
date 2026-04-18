#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int64_t> s;
        for (size_t i = 0, numsLength = nums.size(); i < numsLength; ++i) {
            auto it = s.lower_bound(static_cast<int64_t>(nums[i]) - valueDiff);
            if (it != s.cend() && *it <= static_cast<int64_t>(nums[i]) + valueDiff) return true;
            s.insert(static_cast<int64_t>(nums[i]));
            if (static_cast<int>(i) >= indexDiff) s.erase(static_cast<int64_t>(nums[i - indexDiff]));
        }
        return false;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {1, 2, 3, 1};
    cout << s.containsNearbyAlmostDuplicate(nums1, 3, 0) << endl;
    vector<int> nums2 = {1, 5, 9, 1, 5, 9};
    cout << s.containsNearbyAlmostDuplicate(nums2, 2, 3) << endl;
	return 0;
}
