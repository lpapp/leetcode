#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity_slow(vector<int>& nums) {
      for (size_t i = 0, k = 0; i < nums.size(); ++i) if (!(nums[i]&1)) swap(nums[k++], nums[i]);
      return nums;     
    }

    vector<int> sortArrayByParity(vector<int>& nums) {
      for (int i = 0, j = nums.size() - 1; i < j;) {
        if (nums[i]&1 and !(nums[j]&1)) swap(nums[i], nums[j]);
        if (!(nums[i]&1)) ++i;
        if (nums[j]&1) --j;
      }
      return nums;     
    }
};

void test(vector<int>& nums)
{
  Solution s;
  s.sortArrayByParity(nums);
  for (const int e : nums) cout << e << ",";
  cout << endl;
}

int main()
{
  vector<int> A1{3, 1, 2, 4};
  cout << "[3,1,2,4] => [2,4,3,1]: ";
  test(A1);

  vector<int> A2{0};
  cout << "[0] => [0]: ";
  test(A2);

  return 0;
}
