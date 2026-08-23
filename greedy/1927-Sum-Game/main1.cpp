#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int diff = 0, q = 0;
        for (int i = 0, half = num.size() / 2; i < half; ++i) if (num[i] == '?') ++q; else diff += num[i] - '0';
        for (int i = num.size() / 2, n = num.size(); i < n; ++i) if (num[i] == '?') --q; else diff -= num[i] - '0';
        return 2 * diff + 9 * q;
    }
};

int main()
{
    Solution s;
    assert(!s.sumGame("5023"));
    assert(s.sumGame("25??"));
    assert(!s.sumGame("?3295???"));
    return 0;
}
