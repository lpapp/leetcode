#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findNumbers_no_division(vector<int>& nums) {
      int even_number_of_digits = 0;
      for (const auto e : nums) {
        if ((e >= 10 and e < 100)
            or (e >= 1000 and e < 10000)
            or e == 100000) ++even_number_of_digits;
      }
      return even_number_of_digits;
    }

    int findNumbers_int(vector<int>& nums) {
      int even_number_of_digits = 0;
      for (const auto e : nums) {
        int digits = 0;
        for (int n = e; n > 0; n /= 10, ++digits);
        if (digits & 1) ++even_number_of_digits;
      }
      return even_number_of_digits;
    }

    int findNumbers_bool(vector<int>& nums) {
      int even_number_of_digits = 0;
      for (const auto e : nums) {
        bool digits = true;
        for (int n = e; n > 0; n /= 10, digits = !digits);
        if (digits) ++even_number_of_digits;
      }
      return even_number_of_digits;
    }

    int findNumbers(vector<int>& nums) {
      int even_number_of_digits = 0;
      for (auto e : nums) {
        bool digits = true;
        for (; e > 0; e /= 10, digits = !digits);
        if (digits) ++even_number_of_digits;
      }
      return even_number_of_digits;
    }
};

int main()
{
  Solution s;

  vector<int> A1{12, 345, 2, 6, 7896};
  cout << "[12,345,2,6,7896] => 2: " << s.findNumbers(A1) << endl;

  vector<int> A2{555, 901, 482, 1771};
  cout << "[555, 901, 482, 1771] => 1: " << s.findNumbers(A2) << endl;

  vector<int> A3{100000};
  cout << "[100000] => 1: " << s.findNumbers(A3) << endl;

  vector<int> A4(500, 10);
  cout << "[10, 10, 10, ...] => 500: " << s.findNumbers(A4) << endl;

  return 0;
}
