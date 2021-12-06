#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      const int N = nums.size();
      const int sum = accumulate(nums.cbegin(), nums.cend(), 0);
      for (int i = 0, left_sum = 0; i < N; left_sum += nums[i], ++i) {
        if (left_sum == (sum - left_sum - nums[i])) return i;
      }
      return -1;
    }
};

int main()
{
  Solution s;

  vector<int> A1{1, 7, 3, 6, 5, 6};
  cout << "[1,7,3,6,5,6] => 3: " << s.pivotIndex(A1) << endl;

  vector<int> A2{1, 2, 3};
  cout << "[1,2,3] => -1: " << s.pivotIndex(A2) << endl;

  vector<int> A3{2, 1, -1};
  cout << "[2,1,-1] => 0: " << s.pivotIndex(A3) << endl;

  vector<int> A4{0};
  cout << "[0] => 0: " << s.pivotIndex(A4) << endl;

  return 0;
}
