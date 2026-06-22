#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int magicalString(int n) {
        string s{1, 2, 2};
        for (int i = 2; (int)s.size() < n; ++i) s.insert(s.end(), s[i], 3 - s.back());
        return count(s.cbegin(), s.cbegin() + n, '\1');
    }
};

int main()
{
    Solution s;
    assert(s.magicalString(6) == 3);
    assert(s.magicalString(1) == 1);
    return 0;
}
