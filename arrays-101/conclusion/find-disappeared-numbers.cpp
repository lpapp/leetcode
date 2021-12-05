#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers_space_inefficient(vector<int>& nums) {
      vector<bool> nums_hash(nums.size(), false);
      for (const int e : nums) nums_hash[e - 1] = true;
      vector<int> disappeared_numbers;
      for (size_t i = 0; i < nums_hash.size(); ++i) {
        if (!nums_hash[i]) disappeared_numbers.push_back(i + 1);
      }

      return disappeared_numbers;
    }

    vector<int> findDisappearedNumbers(vector<int>& nums) {
      vector<int> disappeared_numbers;
      for (const int e : nums) nums[abs(e) - 1] = -abs(nums[abs(e) - 1]);
      for (size_t i = 0; i < nums.size(); ++i) if (nums[i] > 0) disappeared_numbers.push_back(i + 1);
      return disappeared_numbers;
    }
};

void test(vector<int>& nums)
{
  Solution s;

  cout << "[";
  for (const int e : s.findDisappearedNumbers(nums)) cout << e << ",";
  cout << "]" << endl;
}

int main()
{
  vector<int> A1{4, 3, 2, 7, 8, 2, 3, 1};
  cout << "[4,3,2,7,8,2,3,1] => [5,6]: ";
  test(A1);

  vector<int> A2{1, 1};
  cout << "[1,1] => 2: ";
  test(A2);

  vector<int> A3{1};
  cout << "[1] => []: ";
  test(A3);

  return 0;
}
