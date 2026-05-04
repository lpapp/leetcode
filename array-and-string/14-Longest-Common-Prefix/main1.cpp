#include <cassert>
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
    vector<string> strs1 = {"flower", "flow", "flight"};
    assert(s.longestCommonPrefix(strs1) == "fl");
    vector<string> strs2 = {"dog", "racecar", "car"};
    assert(s.longestCommonPrefix(strs2) == "");
	return 0;
}
