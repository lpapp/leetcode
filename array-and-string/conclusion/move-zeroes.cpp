#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes_suboptimal(vector<int>& nums) {
      size_t k = 0;
      for (size_t i = 0; i < nums.size(); ++i) if (nums[i]) nums[k++] = nums[i];
      for (; k < nums.size(); ++k) nums[k] = 0;
    }

    void moveZeroes(vector<int>& nums) {
      for (size_t i = 0, k = 0; i < nums.size(); ++i) if (nums[i]) swap(nums[k++], nums[i]);
    }
};

void test(vector<int>& nums)
{
  Solution s;

  s.moveZeroes(nums);
  for (const int e : nums) cout << e << ",";
  cout << endl;
}

int main()
{
  vector<int> A1{0, 1, 0, 3, 12};
  cout << "[0,1,0,3,12] => [1,3,12,0,0]: ";
  test(A1);

  vector<int> A2{0};
  cout << "[0] => [0]: ";
  test(A2);

  return 0;
}
