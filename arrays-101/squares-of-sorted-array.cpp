#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares_sort(vector<int>& nums) {
      const size_t N = nums.size();
      vector<int> squares;
      squares.reserve(N);
      for (size_t i = 0; i < N; ++i) squares.push_back(nums[i] * nums[i]);
      sort(squares.begin(), squares.end());
      return squares;
    }

    vector<int> sortedSquares_hash(vector<int>& nums) {
      vector<int> nums_hash(10001);
      for (const int e : nums) ++nums_hash[abs(e)];

      vector<int> squares;
      squares.reserve(nums.size());
      for (size_t i = 0; i < nums_hash.size(); ++i) {
        if (nums_hash[i]) squares.insert(squares.end(), nums_hash[i], i * i);
      }
      return squares;
    }

    vector<int> sortedSquares(vector<int>& nums) {
      const int N = nums.size();
      vector<int> squares(N);
      for (int begin = 0, end = N - 1, i = N - 1, e = 0; begin <= end; squares[i] = e * e, --i) {
        e = (abs(nums[begin]) >= abs(nums[end])) ? nums[begin++] : nums[end--];
      }
      return squares;
    }
};

void test(vector<int> A)
{
  Solution s;
  vector<int> result = s.sortedSquares(A);
  for (const int e : result) cout << e << ",";
  cout << endl;
}

int main()
{
  vector<int> A1{-4, -1, 0, 3, 10};
  cout << "[-4,-1,0,3,10] => [0,1,9,16,100]: ";
  test(A1);

  vector<int> A2{-7, -3, 2, 3, 11};
  cout << "[-7,-3,2,3,11] => [4,9,9,49,121]: ";
  test(A2);

  vector<int> A3{-10000};
  cout << "[-10000] => [100000000]: ";
  test(A3);

  return 0;
}
