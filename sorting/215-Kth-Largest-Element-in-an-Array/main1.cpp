#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int find(int left, int right, int k, vector<int>& nums) {
            if (left == right) return nums[left];
            int i = left - 1,  j = right + 1, pivot = nums[(left + right) >> 1];
            while (i < j) {
                while (nums[++i] < pivot);
                while (nums[--j] > pivot);
                if (i < j) swap(nums[i], nums[j]);
            }
            return (j < k) ? find(j + 1, right, k, nums) : find(left, j, k, nums);
        };
public:
    int findKthLargest(vector<int>& nums, int k) {
        const size_t n = nums.size();
        k = n - k;
        return find(0, n - 1, k, nums);
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    cout << s.findKthLargest(nums1, 2) << endl;
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << s.findKthLargest(nums2, 4) << endl;
	return 0;
}
