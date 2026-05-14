#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        const int n = nums.size() - 1;
        vector<int> hash(n + 1, 0);
        for (const int num : nums) if (num > n || (++hash[num] > (num == n ? 2 : 1))) return false;
        return true;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {2, 1, 3};
    assert(!s.isGood(nums1));
    vector<int> nums2 = {1, 3, 3, 2};
    assert(s.isGood(nums2));
    vector<int> nums3 = {1, 1};
    assert(s.isGood(nums3));
    vector<int> nums4 = {3, 4, 4, 1, 2, 1};
    assert(!s.isGood(nums4));
    vector<int> nums5 = {2, 2, 2};
    assert(!s.isGood(nums5));
	return 0;
}
