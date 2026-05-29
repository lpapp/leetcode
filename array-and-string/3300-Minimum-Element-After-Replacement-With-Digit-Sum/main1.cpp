#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = numeric_limits<int>::max();
        for (int num : nums) {
            int sum;
            for (sum = 0; num > 0; sum += num % 10, num /= 10);
            res = min(res, sum);
        }
        return res;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {10, 12, 13, 14};
    assert(s.minElement(nums1) == 1);
    vector<int> nums2 = {1, 2, 3, 4};
    assert(s.minElement(nums2) == 1);
    vector<int> nums3 = {999, 19, 199};
    assert(s.minElement(nums3) == 10);
	return 0;
}
