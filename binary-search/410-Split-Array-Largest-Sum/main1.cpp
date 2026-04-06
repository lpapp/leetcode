#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	static bool maxKSubarrays(int maxSum, vector<int>& nums, int k) {
	    int sum = 0, count = 1;
	    for (const int num : nums) {
	        if (sum + num > maxSum) { sum = num; ++count; }
			else sum += num;
	    }
	    return count <= k;
	};

public:
    int splitArray(vector<int>& nums, int k) {
        int left = 0, right = 0;
        for (const int num : nums) { left = max(left, num); right += num; }
        int result = -1;
        while (left <= right) {
            const int mid = left + ((right - left) >> 1);
            if (maxKSubarrays(mid, nums, k)) { result = mid; right = mid - 1; }
			else left = mid + 1;
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<int> nums1 = {7, 2, 5, 10, 8};
    cout << s.splitArray(nums1, 2) << endl;
	vector<int> nums2 = {1, 2, 3, 4, 5};
    cout << s.splitArray(nums2, 2) << endl;
	return 0;
}
