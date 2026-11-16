#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        for (int n = s.size(); n > k; ) {
            int write = 0;
            for (int start = 0; start < n; start += k) {
                int sum = 0;
                for (int i = start, end = min(start + k, n); i < end; ++i) sum += s[i] - '0';
                for (const char digit : to_string(sum)) s[write++] = digit;
            }
            s.resize(n = write);
        }
        return s;
    }
};

int main()
{
    Solution s;
    assert(s.digitSum("11111222223", 3) == "135");
    assert(s.digitSum("00000000", 3) == "000");
    return 0;
}
