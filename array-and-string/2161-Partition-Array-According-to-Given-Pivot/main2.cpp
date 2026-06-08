#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
    	const int n = nums.size();
    	vector<int> res(n);
    	int lo = 0, hi = n - 1;
    	for (int i = 0, j = n - 1; i < n; ++i, --j) {
    	    if (nums[i] < pivot) res[lo++] = nums[i];
    	    if (nums[j] > pivot) res[hi--] = nums[j];
    	}
    	while (lo <= hi) res[lo++] = pivot;
    	return res;
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
	vector<int> nums1 = {9, 12, 5, 10, 14, 3, 10};
    printVector(s.pivotArray(nums1, 10));
	vector<int> nums2 = {-3, 4, 3, 2};
    printVector(s.pivotArray(nums2, 2));
	return 0;
}
