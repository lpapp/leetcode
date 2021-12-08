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

    void rotate_reverse(vector<int>& nums, int k) {
      reverse(nums.begin(), nums.end());
      reverse(nums.begin(), nums.begin() + k % nums.size());
      reverse(nums.begin() + k % nums.size(), nums.end());
    }

    void rotate_swap_first_last(vector<int>& nums, int k) {
      for (int N = nums.size(), steps = k % N, offset = 0; steps; N -= steps, offset += steps, steps %= N) {
        for (int i = 0; i < steps; ++i) swap(nums[offset + i], nums[nums.size() - steps + i]);
      }
    }

    // E.g.
    //  1 2 3 4 5 6 7
    //  k = 5
    //  1 2 -> 3 4
    //  3 4 1 2 5 6 7
    //  --------------
    //  1 2 3 4 5 6 7
    //  k = 2
    //  4 5 -> 6 7
    //  1 2 3 6 7 4 5

    void rotate(vector<int>& nums, int k) {
      for (int offset = 0, N = nums.size(), steps = k % N; steps;) {
        if (N - steps >= steps) {
          for (int i = 0; i < steps; ++i) swap(nums[offset + N - 2 * steps + i], nums[offset + N - steps + i]);
          N -= steps;
          steps %= N;
        } else {
          for (int i = 0; i < N - steps; ++i) swap(nums[offset + i], nums[offset + N - steps + i]);
          int tmp = N - steps;
          N = steps;
          steps -= tmp;
          offset += tmp;
        }
      }
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
