#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int sum = 0;
      for (size_t i = 0; i < nums.size(); ++i) if (!(i&1)) sum += nums[i];
      return sum;
    }
};

int main()
{
  Solution s;

  vector<int> A1{1, 4, 3, 2};
  cout << "[1,4,3,2] => 4: " << s.arrayPairSum(A1) << endl;

  vector<int> A2{6, 2, 6, 5, 1, 2};
  cout << "[6,2,6,5,1,2] => 9: " << s.arrayPairSum(A2) << endl;

  vector<int> A3{-10000, 10000};
  cout << "[-10000, 10000] => -10000: " << s.arrayPairSum(A3) << endl;

  return 0;
}
