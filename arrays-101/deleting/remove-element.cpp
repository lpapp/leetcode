#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int k = 0;
      for (size_t i = 0; i < nums.size(); ++i) if (nums[i] != val) nums[k++] = nums[i];
      return k;
    }
};

void test(vector<int>& nums, int val)
{
  Solution s;

  const int k = s.removeElement(nums, val);
  cout << "" << k << " | ";
  for (int i = 0; i < k; ++i) cout << nums[i] << ", ";
  cout << endl;
}

int main()
{
  vector<int> A1{3, 2, 2, 3};
  cout << "[3,2,2,3] | 3 => [2,2,_,_]: ";
  test(A1, 3);

  vector<int> A2{0, 1, 2, 2, 3, 0, 4, 2};
  cout << "[0,1,2,2,3,0,4,2] | 2 => [0,1,4,0,3,_,_,_]: ";
  test(A2, 2);

  return 0;
}
