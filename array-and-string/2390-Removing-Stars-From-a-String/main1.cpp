#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int i = 0;
        for (const char c : s) { if (c == '*') --i; else s[i++] = c; }
        s.resize(i);
        return s;        
    }
};

int main()
{
    Solution s;
    assert(s.removeStars("leet**cod*e") == "lecoe");
    assert(s.removeStars("erase*****") == "");
    return 0;
}
