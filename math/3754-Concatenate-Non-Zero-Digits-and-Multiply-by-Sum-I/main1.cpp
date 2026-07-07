#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        int sum = 0;
        for (const char c : to_string(n)) {
            const int d = c - '0';
            if (d != 0) { x = x * 10 + d; sum += d; }
        }
        return x * sum;
    }
};

int main()
{
    Solution s;
    assert(s.sumAndMultiply(10203004) == 12340);
    assert(s.sumAndMultiply(1000) == 1);
    assert(s.sumAndMultiply(65463628) == 2618545120);
    return 0;
}
