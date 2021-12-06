#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      const int N = digits.size();
      for (int i = N - 1; i >= 0; digits[i] = 0, --i) {
        if (digits[i] < 9) { ++digits[i]; return digits; };
      }

      digits[0] = 1; digits.push_back(0);
      return digits;
    }
};

void test(vector<int>& digits)
{
  Solution s;

  cout << "[";
  for (const int e : s.plusOne(digits)) cout << e << ",";
  cout << "]" << endl;
}

int main()
{
  vector<int> A1{1, 2, 3};
  cout << "[1,2,3] => [1,2,4]: ";
  test(A1);

  vector<int> A2{4, 3, 2, 1};
  cout << "[4, 3, 2, 1] => [4, 3, 2, 2]: ";
  test(A2);

  vector<int> A3{0};
  cout << "[0] => [1]: ";
  test(A3);

  vector<int> A4{9};
  cout << "[9] => [1,0]: ";
  test(A4);

  return 0;
}
