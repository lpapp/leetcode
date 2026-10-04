#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int loMin = 0;
        for (int hiMax = 0; const char c : s) {
            if (c == '(') ++loMin, ++hiMax;
            else if (c == ')') --loMin, --hiMax;
            else --loMin, ++hiMax;
            if (hiMax < 0) return false;
            loMin = max(loMin, 0);
        }
        return !loMin;
    }
};

int main()
{
    Solution s;
    assert(s.checkValidString("()"));
    assert(s.checkValidString("(*)"));
    assert(s.checkValidString("(*))"));
    assert(!s.checkValidString("("));
    return 0;
}
