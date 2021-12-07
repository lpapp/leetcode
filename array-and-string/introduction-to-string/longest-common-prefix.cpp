#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      for (size_t i = 0; i < strs[0].size(); ++i) {
        for (size_t j = 1; j < strs.size(); ++j) {
          if (strs[0][i] != strs[j][i] or i == strs[j].size()) return strs[0].substr(0, i);
        }
      }
      return strs[0];
    }
};

int main()
{
  Solution s;

  vector<string> A1{"flower", "flow", "flight"};
  cout << "flower | flow | flight => fl: " << s.longestCommonPrefix(A1) << endl;

  vector<string> A2{"dog", "racecar", "car"};
  cout << "dog | racecar | car => '': " << s.longestCommonPrefix(A2) << endl;

  vector<string> A3{"helloworld", "hello", "hell"};
  cout << "helloworld | hello | hell => hell: " << s.longestCommonPrefix(A3) << endl;

  return 0;
}
