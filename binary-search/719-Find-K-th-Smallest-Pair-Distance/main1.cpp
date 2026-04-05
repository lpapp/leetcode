#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int count(int max, vector<int>& nums) {
        int result = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            const int val = nums[i] - max;
            int leftBoundIndex = lower_bound(nums.cbegin(), nums.cend(), val) - nums.cbegin();
            result += i - leftBoundIndex;
        }
        return result;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = -1;
        for (int left = 0, right = nums.back() - nums.front(); left <= right;) {
            const int mid = left + ((right - left) >> 1);
            if (count(mid, nums) >= k) { result = mid; right = mid - 1; }
            else left = mid + 1;
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<int> nums1 = {1, 3, 1};
    cout << s.smallestDistancePair(nums1, 1) << endl;
	vector<int> nums2 = {1, 1, 1};
    cout << s.smallestDistancePair(nums2, 2) << endl;
	vector<int> nums3 = {1, 6, 1};
    cout << s.smallestDistancePair(nums3, 3) << endl;
	return 0;
}
