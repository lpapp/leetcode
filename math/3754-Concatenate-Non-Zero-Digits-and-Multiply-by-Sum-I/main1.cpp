#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0, sum = 0;
        for (char c : to_string(n)) {
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
    return 0;
}
