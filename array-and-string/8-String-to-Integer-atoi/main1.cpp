#include <cassert>
#include <cctype>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') ++i;
        if (i == n) return 0;
        int sign = 1;
        if (s[i] == '-') sign = -1;
        if (s[i] == '-' || s[i] == '+') ++i;
        int res = 0;
        for (int overflow = numeric_limits<int>::max() / 10; i < n; ++i) {
            if (!isdigit(s[i])) break;
            int digit = s[i] - '0';
            if (res > overflow || (res == overflow && digit > 7)) return (sign == 1) ? numeric_limits<int>::max() : numeric_limits<int>::min();
            res = res * 10 + digit;
        }
        return res * sign;       
    }
};

int main()
{
	Solution s;
    assert(s.myAtoi("42") == 42);
    assert(s.myAtoi(" -042") == -42);
    assert(s.myAtoi("1337c0d3") == 1337);
    assert(!s.myAtoi("0-1"));
    assert(!s.myAtoi("words and 987"));
    assert(s.myAtoi("-91283472332") == -2147483648);
	return 0;
}
