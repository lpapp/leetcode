#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
         vector<int> result;
        for (const int num : nums) if (num < pivot) result.push_back(num);
        for (const int num : nums) if (num == pivot) result.push_back(num);
        for (const int num : nums) if (num > pivot) result.push_back(num);
        return result;      
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
