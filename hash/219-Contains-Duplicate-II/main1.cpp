#include <cassert>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        for (int l = 0, r = 0, n = nums.size(); r < n; ++r) {
            if (r - l > k) s.erase(nums[l++]);
            if (!s.insert(nums[r]).second) return true;
        }
        return false;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {1, 2, 3, 1};
    assert(s.containsNearbyDuplicate(nums1, 3));
    vector<int> nums2 = {1, 0, 1, 1};
    assert(s.containsNearbyDuplicate(nums2, 1));
    vector<int> nums3 = {1, 2, 3, 1, 2, 3};
    assert(!s.containsNearbyDuplicate(nums3, 2));
	return 0;
}
