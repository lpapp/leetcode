#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
      string added;
      for (int ai = a.size() - 1, bi = b.size() - 1, carry = 0, curr_digit = 0; ai >= 0 or bi >= 0 or carry; added.push_back('0' + curr_digit), curr_digit = carry) {
        carry = 0;
        if (ai >= 0) curr_digit += a[ai--] - '0';
        if (bi >= 0) curr_digit += b[bi--] - '0';
        if (curr_digit > 1) { curr_digit -= 2; ++carry; }
      }
      reverse(added.begin(), added.end());
      return added;
    }
};

int main()
{
  Solution s;

  string A1 = "11", B1 = "1";
  cout << "11 + 1 => 100: " << s.addBinary(A1, B1) << endl;

  string A2 = "1010", B2 = "1011";
  cout << "1010 + 1011 => 10101: " << s.addBinary(A2, B2) << endl;

  string A3 = "1", B3 = "1";
  cout << "1 + 1 => 10: " << s.addBinary(A3, B3) << endl;

  string A4 = "1", B4 = "100001";
  cout << "1 + 100001 => 100010: " << s.addBinary(A4, B4) << endl;

  return 0;
}
