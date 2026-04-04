#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
    int find(const vector<int>& nums1, const vector<int>& nums2, int nums1Index, int nums1Length, int nums2Index, int nums2Length, int k) {
        if (nums1Index >= nums1Length) return nums2[nums2Index + k - 1];
        if (nums2Index >= nums2Length) return nums1[nums1Index + k - 1];
        if (k == 1) return min(nums1[nums1Index], nums2[nums2Index]);
        const int mid = k / 2;
        const int num1 = (nums1Index + mid - 1 < nums1Length) ? nums1[nums1Index + mid - 1] : numeric_limits<int>::max();
        const int num2 = (nums2Index + mid - 1 < nums2Length) ? nums2[nums2Index + mid - 1] : numeric_limits<int>::max();
        return num1 < num2 ? find(nums1, nums2, nums1Index + mid, nums1Length, nums2Index, nums2Length, k - mid) : find(nums1, nums2, nums1Index, nums1Length, nums2Index + mid, nums2Length, k - mid);
    };
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int nums1Length = nums1.size();
        const int nums2Length = nums2.size();
        const int length = nums1Length + nums2Length;
        const int firstMid = find(nums1, nums2, 0, nums1Length, 0, nums2Length, (length + 1) / 2);
        const int secondMid = find(nums1, nums2, 0, nums1Length, 0, nums2Length, (length + 2) / 2);
        return (firstMid + secondMid) / 2.0;
    }
};


int main()
{
	Solution s;
	vector<int> nums11 = {1, 3};
	vector<int> nums12 = {2};
    cout << s.findMedianSortedArrays(nums11, nums12) << endl;
	vector<int> nums21 = {1, 2};
	vector<int> nums22 = {3, 4};
    cout << s.findMedianSortedArrays(nums21, nums22) << endl;
	return 0;
}
