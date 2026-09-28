#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        for (int depth = 0; const char c : s) {
            if (c == '(') res = max(res, ++depth);
            else if (c == ')') --depth;
        }
        return res;
    }
};

int main()
{
    Solution s;
    assert(s.maxDepth("(1+(2*3)+((8)/4))+1") == 3);
    assert(s.maxDepth("(1)+((2))+(((3)))") == 3);
    assert(s.maxDepth("()(())((()()))") == 3);
    return 0;
}
