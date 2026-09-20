#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size(), weighted = 0;
        for (int i = 0; i < n; ++i) weighted += (i + 1) * (s[i] - 'a');
        return 26 * (n * (n + 1) / 2) - weighted;   
    }
};

int main()
{
    Solution s;
    assert(s.reverseDegree("abc") == 148);
    assert(s.reverseDegree("zaza") == 160);
    return 0;
}
