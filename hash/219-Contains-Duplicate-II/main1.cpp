#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hash;
        for (size_t left = 0, right = 0; right < nums.size(); ++right) {
            if (static_cast<int>(right - left) > k) hash.erase(nums[left++]);
            if (hash.contains(nums[right])) return true;
            hash.insert(nums[right]);
        }
        return false;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {1, 2, 3, 1};
    cout << s.containsNearbyDuplicate(nums1, 3) << endl;
    vector<int> nums2 = {1, 0, 1, 1};
    cout << s.containsNearbyDuplicate(nums2, 1) << endl;
    vector<int> nums3 = {1, 2, 3, 1, 2, 3};
    cout << s.containsNearbyDuplicate(nums3, 2) << endl;
	return 0;
}
