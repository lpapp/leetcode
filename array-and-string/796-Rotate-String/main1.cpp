#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).contains(goal);
    }
};

int main()
{
	Solution s;
    assert(s.rotateString("abcde", "cdeab"));
    assert(!s.rotateString("abcde", "abced"));
	return 0;
}
