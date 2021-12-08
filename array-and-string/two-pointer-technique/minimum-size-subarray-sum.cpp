#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Caterpillar method, which is a two pointer technique after all.
    int minSubArrayLen(int target, vector<int>& nums) {
      int min_size = 100001, N = nums.size();
      for (int back = 0, front = 0, sum = 0; back < N; sum -= nums[back], ++back) {
        while (front < N and sum < target) sum += nums[front++];
        if (sum >= target) min_size = min(min_size, front - back);
      }
      return min_size == 100001 ? 0 : min_size;
    }
};

int main()
{
  Solution s;

  vector<int> A1{2, 3, 1, 2, 4, 3};
  cout << "[2,3,1,2,4,3] | 7 => 2: " << s.minSubArrayLen(7, A1) << endl;

  vector<int> A2{1, 4, 4};
  cout << "[1,4,4] | 4 => 1: " << s.minSubArrayLen(4, A2) << endl;

  vector<int> A3{1, 1, 1, 1, 1, 1, 1, 1};
  cout << "[1,1,1,1,1,1,1,1] | 11 => 0: " << s.minSubArrayLen(11, A3) << endl;

  vector<int> A4{10000};
  cout << "[10000] | 10000 => 1: " << s.minSubArrayLen(10000, A4) << endl;

  vector<int> A5{1, 2, 3, 4, 5};
  cout << "[1,2,3,4,5] | 11 => 3: " << s.minSubArrayLen(11, A5) << endl;

  return 0;
}
