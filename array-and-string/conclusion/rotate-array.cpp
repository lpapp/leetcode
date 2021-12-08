#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate_extra_space(vector<int>& nums, int k) {
      const size_t N = nums.size();
      vector<int> rotated(N);
      for (size_t i = 0; i < N; ++i) rotated[(i + k) % N] = nums[i];
      nums = rotated;
    }

    void rotate_cycle(vector<int>& nums, int k) {
      const int N = nums.size();
      for (int i = 0, ci = 0; i < N; ++ci) {
        int j = ci, prev_tmp = nums[j], curr_tmp = 0;
        do {
          curr_tmp = nums[(j + k) % N];
          nums[(j + k) % N] = prev_tmp;
          prev_tmp = curr_tmp;
          ++i,
          j = (j + k) % N;
        } while (j != ci);
      }
    }

    void rotate(vector<int>& nums, int k) {
      reverse(nums.begin(), nums.end());
      reverse(nums.begin(), nums.begin() + k % nums.size());
      reverse(nums.begin() + k % nums.size(), nums.end());
    }
};

void test(vector<int>& nums, int k)
{
  Solution s;
  s.rotate(nums, k);

  cout << "[";
  for (const int e : nums) cout << e << ",";
  cout << "]" << endl; 
}

int main()
{
  vector<int> A1{1, 2, 3, 4, 5, 6, 7};
  cout << "[1,2,3,4,5,6,7] | 3 => [5,6,7,1,2,3,4]: ";
  test(A1, 3);

  vector<int> A2{-1, -100, 3, 99};
  cout << "[-1,-100,3,99] | 2 => [3,99,-1,-100]: ";
  test(A2, 2);

  vector<int> A3{1, 2, 3, 4, 5, 6, 7};
  cout << "[1,2,3,4,5,6,7] | 10 => [5,6,7,1,2,3,4]: ";
  test(A3, 10);

  vector<int> A4{1};
  cout << "[1] | 100000 => [1]: ";
  test(A4, 100000);

  vector<int> A5{-1};
  cout << "[-1] | 0 => [-1]: ";
  test(A5, 0);

  vector<int> A6{1, 2, 3, 4, 5, 6};
  cout << "[1,2,3,4,5,6] | 3 => [4,5,6,1,2,3]: ";
  test(A6, 3);

  return 0;
}
