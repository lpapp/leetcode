#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = numeric_limits<int>::max(), mid = numeric_limits<int>::max();
        for (const int num : nums) {
            if (num > mid) return true;
            if (num <= min) min = num;
            else mid = num;
        }
        return false;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    assert(s.increasingTriplet(nums1));
    vector<int> nums2 = {5, 4, 3, 2, 1};
    assert(!s.increasingTriplet(nums2));
    vector<int> nums3 = {2, 1, 5, 0, 4, 6};
    assert(s.increasingTriplet(nums3));
	return 0;
}
