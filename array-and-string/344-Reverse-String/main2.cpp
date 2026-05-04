#include <cassert>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) swap(s[i], s[j]);
    }
};

int main()
{
	Solution s;
    vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    vector<char> res1 = {'o', 'l', 'l', 'e', 'h'};
    s.reverseString(s1);
    assert(s1 == res1);
    vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    vector<char> res2 = {'h', 'a', 'n', 'n', 'a', 'H'};
    s.reverseString(s2);
    assert(s2 == res2);
	return 0;
}
