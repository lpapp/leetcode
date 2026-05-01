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

    // E.g.
    //  1 2 3 4 5 6 7
    //  k = 3, N = 7
    // i = 0, j = 0, ci = 0 => prev_tmp = 4 => nums = 1 2 3 1 5 6 7
    // i = 1, j = 3, ci = 0 => prev_tmp = 7 => nums = 1 2 3 1 5 6 4
    // i = 2, j = 6, ci = 0 => prev_tmp = 3 => nums = 1 2 7 1 5 6 4
    // i = 3, j = 2, ci = 0 => prev_tmp = 6 => nums = 1 2 7 1 5 3 4
    // i = 4, j = 5, ci = 0 => prev_tmp = 2 => nums = 1 6 7 1 5 3 4
    // i = 5, j = 1, ci = 0 => prev_tmp = 5 => nums = 1 6 7 1 2 3 4
    // i = 6, j = 4, ci = 0 => prev_tmp = 1 => nums = 5 6 7 1 2 3 4
    // i = 7, j = 0, ci = 0 => end both loops
    //
    // 1 2 3 4 5 6
    // k = 3, N = 6
    // 1 2 3 1 5 6
    // 4 2 3 1 5 6
    // 4 2 3 1 2 6
    // 4 5 3 1 2 6
    // 4 5 3 1 2 3
    // 4 5 6 1 2 3
    // We rotate each element by k starting from the beginning. If we get
    // back to an index that we already shifted, and have not rotated all
    // indices yet, we increment the current index by one and start
    // rotating again until we either come back to that index or finished
    // rotating all indices.
    void rotate_cycle(vector<int>& nums, int k) {
      std::cout << std::endl;
      const int N = nums.size();
      for (int i = 0, ci = 0; i < N; ++ci) {
        int j = ci, prev_tmp = nums[j];
        do {
          j = (j + k) % N;
          std::swap(nums[j], prev_tmp);
          ++i;
        } while (j != ci);
      }
    }

    // E.g.
    //  1 2 3 4 5 6 7
    //  k = 3
    //  7 6 5 4 3 2 1
    //  5 6 7 4 3 2 1
    //  5 6 7 1 2 3 4
    void rotate_reverse(vector<int>& nums, int k) {
      reverse(nums.begin(), nums.end());
      reverse(nums.begin(), nums.begin() + k % nums.size());
      reverse(nums.begin() + k % nums.size(), nums.end());
    }

    // E.g.
    //  1 2 3 4 5 6 7
    //  k = 3, N = 7
    //
    // 5 2 3 4 1 6 7
    // 5 6 3 4 1 2 7
    // 5 6 7 4 1 2 3
    // offset = 3, N = 4, step = 3
    // 5 6 7 1 4 2 3
    // 5 6 7 1 2 4 3
    // 5 6 7 1 2 3 4
    //
    // 1 2 3 4 5 6
    // k = 3, N = 6
    // 4 2 3 1 5 6
    // 4 5 3 1 2 6
    // 4 5 6 1 2 3
    //
    //  1 2 3 4 5 6 7 8
    //  k = 3, N = 8
    // 6 2 3 4 5 1 7 8
    // 6 7 3 4 5 1 2 8
    // 6 7 8 4 5 1 2 3
    // offset = 3, N = 5, step = 3
    // 6 7 8 1 5 4 2 3
    // 6 7 8 1 2 4 5 3
    // 6 7 8 1 2 3 5 4
    // offset = 6, N = 2, step = 1
    // 6 7 8 1 2 3 4 5
    //
    // N=11, steps=3, diff=8, offset=0
    // 1 2 3 4 5 9 7 8 6 10 11 
    // 1 2 3 4 5 9 10 8 6 7 11 
    // 1 2 3 4 5 9 10 11 6 7 8 
    // N=8, steps=3, diff=5, offset=0
    // 1 2 9 4 5 3 10 11 6 7 8 
    // 1 2 9 10 5 3 4 11 6 7 8 
    // 1 2 9 10 11 3 4 5 6 7 8 
    // N=5, steps=3, diff=2, offset=0
    // 9 2 1 10 11 3 4 5 6 7 8 
    // 9 10 1 2 11 3 4 5 6 7 8 
    // N=3, steps=1, diff=2, offset=2
    // 9 10 1 11 2 3 4 5 6 7 8 
    // N=2, steps=1, diff=1, offset=2
    // 9 10 11 1 2 3 4 5 6 7 8 
    // [9,10,11,1,2,3,4,5,6,7,8,]
    //
    // Swap first and last k elements, then if it is not done yet, because
    // there are untouched items in the middle, those need to be moved to
    // the end. Keep doing this in max k chunks, and we will eventually
    // arrive at the solution.
    void rotate_swap_first_last(vector<int>& nums, int k) {
      for (int N = nums.size(), steps = k % N, offset = 0; steps; N -= steps, offset += steps, steps %= N) {
        for (int i = 0; i < steps; ++i) { swap(nums[offset + i], nums[nums.size() - steps + i]); for (int e : nums) std::cout << e << " "; std::cout << std::endl; }
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
    //
    // E.g.
    //  1 2 3 4 5 6 7
    //  k = 3, N = 7
    // 1 5 3 4 2 6 7
    // 1 5 6 4 2 3 7
    // 1 5 6 7 2 3 4
    // N = 4, steps = 3
    // 5 1 6 7 2 3 4
    // N = 3, steps = 2, offset = 1
    // 5 6 1 7 2 3 4
    // N = 2, steps = 1, offset = 2
    // 5 6 7 1 2 3 4
    // N = 1, steps = 0
    //
    // 1 2 3 4 5 6
    // 4 2 3 1 5 6
    // 4 5 3 1 2 6
    // 4 5 6 1 2 3
    // k = 3, N = 6
    //
    //  1 2 3 4 5 6 7 8
    //  k = 3, N = 8, diff = 5, offset = 0
    // 1 2 6 4 5 3 7 8
    // 1 2 6 7 5 3 4 8
    // 1 2 6 7 8 3 4 5
    // N = 5, steps = 3, diff = 2, offset = 0
    // 6 2 1 7 8 3 4 5
    // 6 7 1 2 8 3 4 5
    // N = 3, steps = 1, offset = 2, diff = 2 (replace index 3 and 4)
    // 6 7 1 8 2 3 4 5
    // N = 2, steps = 1, offset = 2, diff = 1 (replace index 2 and 3)
    // 6 7 8 1 2 3 4 5
    // N = 1, steps = 0, offset = 2, diff = 1
    //
    // 1 2 3 4 5 6 7 8 9 10 11 
    // N=11, steps=3, diff=8, offset=0
    // 1 2 3 4 5 9 7 8 6 10 11 
    // 1 2 3 4 5 9 10 8 6 7 11 
    // 1 2 3 4 5 9 10 11 6 7 8 
    // N=8, steps=3, diff=5, offset=0
    // 1 2 9 4 5 3 10 11 6 7 8 
    // 1 2 9 10 5 3 4 11 6 7 8 
    // 1 2 9 10 11 3 4 5 6 7 8 
    // N=5, steps=3, diff=2, offset=0
    // 9 2 1 10 11 3 4 5 6 7 8 
    // 9 10 1 2 11 3 4 5 6 7 8 
    // N=3, steps=1, diff=2, offset=2
    // 9 10 1 11 2 3 4 5 6 7 8 
    // N=2, steps=1, diff=1, offset=2
    // 9 10 11 1 2 3 4 5 6 7 8 
    //
    // Algorithm: Shift the last k elements to the left as much as possible
    // given in k units. If there are some numbers left on the left, fewer than
    // k units, then we get the remaining left elements correct by shifting
    // that many items from the last k units on the left to the left. Then,
    // finally, move the remaining items from the leftmost k units to the left
    // to form k units on the left. This way, the whole array gets rotated
    // correctly.
    // 
    void rotate(vector<int>& nums, int k) {
      for (int offset = 0, N = nums.size(), steps = k % N, diff = N - steps; steps; diff = N - steps) {
        std::cout << "N=" << N << ", steps=" << steps << ", diff=" << diff << ", offset=" << offset << std::endl;
        if (diff >= steps) {
          for (int i = 0; i < steps; ++i) { swap(nums[offset + diff - steps + i], nums[offset + diff + i]); for (auto e : nums) std::cout << e << " "; std::cout << std::endl; }
          N -= steps;
          steps %= N;
        } else {
          for (int i = 0; i < diff; ++i) { swap(nums[offset + i], nums[offset + diff + i]); for (auto e : nums) std::cout << e << " "; std::cout << std::endl;}
          N = steps;
          steps -= diff;
          offset += diff;
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

  vector<int> A8{1, 2, 3, 4, 5, 6, 7, 8};
  cout << "[1,2,3,4,5,6,7,8] | 3 => [6,7,8,1,2,3,4,5]: ";
  test(A8, 3);

  vector<int> A9{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  cout << "[1,2,3,4,5,6,7,8,9,10,11] | 3 => [9,10,11,1,2,3,4,5,6,7,8]: ";
  test(A9, 3);

  return 0;
}
