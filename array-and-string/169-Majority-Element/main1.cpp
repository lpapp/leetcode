#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, result = 0;
        for (const int num : nums) {
            if (count == 0) { result = num; count = 1; }
            else (result == num) ? ++count : --count;
        }
        return result;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {3, 2, 3};
    cout << s.majorityElement(nums1) << endl;
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << s.majorityElement(nums2) << endl;
	return 0;
}
