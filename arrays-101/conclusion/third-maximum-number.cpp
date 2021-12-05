#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
      int distinct_max = nums[0];
      unordered_set<int> nums_hash{distinct_max};
      for (size_t i = 1, counter = 1; i < nums.size(); ++i) {
        if (!nums_hash.count(nums[i])) {
          nums_hash.insert(nums[i]);
          if (++counter == 3) return nums[i];
          else distinct_max = max(distinct_max, nums[i]);
         }
      };

      return distinct_max;
    }
};

int main()
{
  Solution s;

  vector<int> A1{3, 2, 1};
  cout << "[3,2,1] => 1: " << s.thirdMax(A1) << endl;

  vector<int> A2{1, 2};
  cout << "[1,2] => 2: " << s.thirdMax(A2) << endl;

  vector<int> A3{2, 2, 3, 1};
  cout << "[2,2,3,1] => 1: " << s.thirdMax(A3) << endl;

  vector<int> A4{-1};
  cout << "[-1] => -1: " << s.thirdMax(A4) << endl;

  vector<int> A5{-100, 0, -100, -100, 0};
  cout << "[-100, 0, -100, -100, 0] => 0: " << s.thirdMax(A5) << endl;

  vector<int> A6{1, 2, 2, 5, 3, 5};
  cout << "[1,2,2,5,3,5] => 2: " << s.thirdMax(A6) << endl;

  return 0;
}
