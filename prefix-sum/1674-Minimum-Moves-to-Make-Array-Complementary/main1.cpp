#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        const int n = nums.size();
        vector<int> diff(limit * 2 + 2, 0);
        for (int i = 0; i < n / 2; ++i) {
            int minNum = nums[i], maxNum = nums[n - i - 1];
            if (minNum > maxNum) swap(minNum, maxNum);
            diff[2] += 2;
            diff[minNum + 1] -= 1;
            diff[minNum + maxNum] -= 1;
            diff[minNum + maxNum + 1] += 1;
            diff[maxNum + limit + 1] += 1;
        }
        int res = n;
        for (int i = 2, cost = 0; i <= limit * 2; ++i) { cost += diff[i]; res = min(res, cost); }
        return res;
    }
};

int main()
{
	Solution s;
	vector<int> nums1 = {1, 2, 4, 3};
	assert(s.minMoves(nums1, 4) == 1);
	vector<int> nums2 = {1, 2, 2, 1};
	assert(s.minMoves(nums2, 2) == 2);
	vector<int> nums3 = {1, 2, 1, 2};
	assert(s.minMoves(nums3, 2) == 0);
	return 0;
}
