#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int find(bool findGreater, vector<int>& nums, int target) {
        int result = -1;
        for (int left = 0, right = nums.size() - 1; left <= right;) {
            const int mid = left + ((right - left) >> 1);
            const bool found = findGreater ? nums[mid] > target : nums[mid] >= target;
            if (found) { result = mid; right = mid - 1; }
            else left = mid + 1;
        }
        return result;
    };
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (!nums.size()) return {-1, -1};
        const int start = find(false, nums, target);
        if (start == -1 || nums[start] != target) return {-1, -1};
        int end = find(true, nums, target);
        if (end == -1) end = nums.size() - 1;
        else --end;
        return {start, end};
    }
};

void printVector(vector<int> input)
{
    for (const int item : input) cout << item << ", ";
    cout << endl;
}

int main()
{
	Solution s;
	vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    printVector(s.searchRange(nums1, 8));
	vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    printVector(s.searchRange(nums2, 6));
	vector<int> nums3 = {};
    printVector(s.searchRange(nums3, 0));
	vector<int> nums4 = {1};
    printVector(s.searchRange(nums4, 0));
	return 0;
}
