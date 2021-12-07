#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int arrayPairSum_sort(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int sum = 0;
      for (size_t i = 0; i < nums.size(); i += 2) sum += nums[i];
      return sum;
    }

    int arrayPairSum(vector<int>& nums) {
      vector<int> nums_hash(20001, 0);
      for (const int e : nums) ++nums_hash[e + 10000];
      int sum = 0;
      bool minimum = true;
      for (size_t i = 0; i < nums_hash.size();) {
        if (nums_hash[i]) { if (minimum) sum += i - 10000; minimum = !minimum; --nums_hash[i]; }
        else ++i;
      }
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
