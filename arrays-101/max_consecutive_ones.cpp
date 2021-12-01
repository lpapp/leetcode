#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int max_consecutive_ones = 0;
      int consecutive_ones = 0;
      for (const int e : nums) {
        if (e == 1) ++consecutive_ones;
        else { max_consecutive_ones = max(max_consecutive_ones, consecutive_ones); consecutive_ones = 0; }
      }
      max_consecutive_ones = max(max_consecutive_ones, consecutive_ones);
      return max_consecutive_ones;
    }
};

int main()
{
  Solution s;

  vector<int> A1{1, 1, 0, 1, 1, 1};
  cout << "[1,1,0,1,1,1] => 3: " << s.findMaxConsecutiveOnes(A1) << endl;

  vector<int> A2{1, 0, 1, 1, 0, 1};
  cout << "[1,0,1,1,0,1] => 2: " << s.findMaxConsecutiveOnes(A2) << endl;

  vector<int> A3{0};
  cout << "[0] => 0: " << s.findMaxConsecutiveOnes(A3) << endl;

  vector<int> A4{1};
  cout << "[1] => 1: " << s.findMaxConsecutiveOnes(A4) << endl;

  vector<int> A5(100000, 1);
  cout << "[1, 1, 1, ...] => 100000: " << s.findMaxConsecutiveOnes(A5) << endl;

  return 0;
}
