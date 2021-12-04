#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if (nums.empty()) return 0;
      int k = 1;                                                       
      for (size_t i = 1; i < nums.size(); ++i) if (nums[i] != nums[i - 1]) nums[k++] = nums[i];
      return k;
    }
};

void test(vector<int>& nums)
{
  Solution s;

  const int k = s.removeDuplicates(nums);
  cout << k << " | ";
  for (const int e : nums) cout << e << ",";
  cout << endl;
}

int main()
{
  vector<int> A1{1, 1, 2};
  cout << "[1,1,2] => [1,2,_]: ";
  test(A1);

  vector<int> A2{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  cout << "[0,0,1,1,1,2,2,3,3,4] => [0,1,2,3,4,_,_,_,_,_]: ";
  test(A2);

  return 0;
}
