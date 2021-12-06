#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
      int max = nums[0], max_index = 0, sec_max = 0;
      for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] > max) { sec_max = max; max = nums[i]; max_index = i; }
        else if (nums[i] > sec_max) sec_max = nums[i];
      }
      return (max >= (2 * sec_max)) ? max_index : -1;
    }
};

int main()
{
  Solution s;

  vector<int> A1{3, 6, 1, 0};
  cout << "[3,6,1,0] => 1: " << s.dominantIndex(A1) << endl;

  vector<int> A2{1, 2, 3, 4};
  cout << "[1,2,3,4] => -1: " << s.dominantIndex(A2) << endl;

  vector<int> A3{1};
  cout << "[1] => 0: " << s.dominantIndex(A3) << endl;

  vector<int> A4{0, 0};
  cout << "[0, 0] => 0: " << s.dominantIndex(A4) << endl;

  vector<int> A5{100, 100};
  cout << "[100, 100] => -1: " << s.dominantIndex(A5) << endl;

  return 0;
}
