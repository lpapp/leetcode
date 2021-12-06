#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
      const int N = nums.size();
      for (int i = 0, left_sum = 0, sum = accumulate(nums.cbegin(), nums.cend(), 0); i < N; left_sum += nums[i], ++i) {          
        if (left_sum == (sum - left_sum - nums[i])) return i;                   
      }                                                                         
      return -1;
    }
};

int main()
{
  Solution s;

  vector<int> A1{2, 3, -1, 8, 4};
  cout << "[2,3,-1,8,4] => 3: " << s.findMiddleIndex(A1) << endl;

  vector<int> A2{1, -1, 4};
  cout << "[1,-1,4] => 2: " << s.findMiddleIndex(A2) << endl;

  vector<int> A3{2, 5};
  cout << "[2,5} => -1: " << s.findMiddleIndex(A3) << endl;

  vector<int> A4{1};
  cout << "[1] => 0: " << s.findMiddleIndex(A4) << endl;

  return 0;
}
