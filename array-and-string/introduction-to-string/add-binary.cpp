#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
      string added;
      for (int ai = a.size() - 1, bi = b.size(), carry = 0; ai >= 0 or bi >= 0; --ai, --bi) {
        char c;
        if (a[ai] == '1' and b[ai] == '1') c = carry ? '1' : '0';
        else if (a[ai] == '1' or b[ai] == '1') c = carry ? '0' : '1';
        else c = carry-- ? '1' : '0';
        added.push_back(c);
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

  return 0;
}
