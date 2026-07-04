#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(string s1, string s2) {
        const int n = s1.size();
        if (n == 1 && s1[0] == '1' && s2[0] == '0') return -1;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (s1[i] == '0' && s2[i] == '1') ++res;
            else if (s1[i] == '1' && s2[i] == '0') {
                if (i + 1 < n && s1[i + 1] == '1' && s2[i + 1] == '0') { ++res; ++i; }
                else res += 2;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    assert(s.minOperations("11", "00") == 1);
    assert(s.minOperations("01", "10") == 3);
    assert(s.minOperations("1", "0") == -1);
    return 0;
}
