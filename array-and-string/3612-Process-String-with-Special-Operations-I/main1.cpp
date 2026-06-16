#include <algorithm>
#include <cassert>
#include <cctype>
#include <string>

using namespace std;

class Solution {
public:
    string processStr(string s) {
        string res;
        for (const char c : s) {
            if (isalpha(c)) res += c;
            else if (c == '*' && !res.empty()) res.pop_back();
            else if (c == '#') res += res;
            else if (c == '%') reverse(res.begin(), res.end());
        }
        return res;
    }
};

int main()
{
    Solution s;
    assert(s.processStr("a#b%*") == "ba");
    assert(s.processStr("z*#") == "");
    return 0;
}
