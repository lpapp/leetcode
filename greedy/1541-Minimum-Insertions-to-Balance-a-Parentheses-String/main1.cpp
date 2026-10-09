#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int res = 0, need = 0;
        for (const char c : s) {
            if (c == '(') { need += 2; if (need & 1) { ++res; --need; } }
            else { --need; if (need < 0) { ++res; need = 1; } }
        }
        return res + need;
    }
};

int main()
{
    Solution s;
    assert(s.minInsertions("(()))") == 1);
    assert(s.minInsertions("())") == 0);
    assert(s.minInsertions("))())(") == 3);
    return 0;
}
