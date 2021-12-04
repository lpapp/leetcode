#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> replaceElements_slow(vector<int>& arr) {
      const size_t N = arr.size();
      for (size_t i = 0; i < N - 1; ++i) {
        int max_right = 0;
        for (size_t j = i + 1; j < N; ++j) {
          max_right = max(max_right, arr[j]);
        }
        arr[i] = max_right;
      }
      arr[N - 1] = -1;
      return arr;   
    }

    vector<int> replaceElements(vector<int>& arr) {
      for (int i = arr.size() - 1, prev_max = -1, curr_max = 0; i >= 0; --i, prev_max = curr_max) {
        curr_max = max(curr_max, arr[i]);
        arr[i] = prev_max;
      }
      return arr;   
    }
};

void test(vector<int>& arr)
{
  Solution s;
  for (const int e : s.replaceElements(arr)) cout << e << ",";
  cout << endl;
}

int main()
{
  vector<int> A1{17, 18, 5, 4, 6, 1};
  cout << "[17,18,5,4,6,1] => [18,6,6,6,1,-1]: ";
  test(A1);

  vector<int> A2{400};
  cout << "[400] => [-1]: ";
  test(A2);

  return 0;
}
