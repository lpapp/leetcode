#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0, open = 0;
        for (const char c : s) {
            if (c == '(') ++open;
            else if (open) --open;
            else ++res;
        }
        return res + open;   
    }
};

int main()
{
    Solution s;
    assert(s.minAddToMakeValid("())") == 1);
    assert(s.minAddToMakeValid("(((") == 3);
    return 0;
}
