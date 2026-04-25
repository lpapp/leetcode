#include <iostream>
#include <vector>

using namespace std;

class Solution {                                                                
public:                                                                         
    int findMaxConsecutiveOnes(vector<int>& nums) {                             
      int max_consecutive_ones = 0, consecutive_ones = 0;                       
      for (const int e : nums) max_consecutive_ones = max(max_consecutive_ones, consecutive_ones = (e ? consecutive_ones + 1 : 0));
      return max_consecutive_ones;                                       
    }                                                                           
};

int main()
{
	Solution s;
    vector<int> nums1 = {1, 1, 0, 1, 1, 1};
    cout << s.findMaxConsecutiveOnes(nums1) << endl;
    vector<int> nums2 = {1, 0, 1, 1, 0, 1};
    cout << s.findMaxConsecutiveOnes(nums2) << endl;
	return 0;
}
