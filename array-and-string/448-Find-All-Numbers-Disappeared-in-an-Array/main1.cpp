#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      vector<int> disappeared_numbers;                                          
      for (const int e : nums) nums[abs(e) - 1] = -abs(nums[abs(e) - 1]);       
      for (size_t i = 0; i < nums.size(); ++i) if (nums[i] > 0) disappeared_numbers.push_back(i + 1);
      return disappeared_numbers;
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
	vector<int> nums1 = {4, 3, 2, 7, 8, 2, 3, 1};
    printVector(s.findDisappearedNumbers(nums1));
	vector<int> nums2 = {1, 1};
    printVector(s.findDisappearedNumbers(nums2));
	return 0;
}
