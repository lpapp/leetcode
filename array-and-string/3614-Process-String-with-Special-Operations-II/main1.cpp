#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    char processStr(string s, long long k) {
        const int size = s.size();
        long long length = 0;
        for (int i = 0; i < size; ++i) {
            if (s[i] == '#') length = min(length * 2, (long long)2e15);
            else if (s[i] == '*') length = max(0LL, length - 1);
            else if (s[i] != '%') ++length;
        }
        if (k >= length) return '.';
        for (int i = size - 1; i >= 0; --i) {
            if (s[i] == '#') { length /= 2; k %= length; }
            else if (s[i] == '*') ++length;
            else if (s[i] == '%') k = length - 1 - k;
            else { --length; if (k == length) return s[i]; }
        }
        return '.';
    }
};

int main()
{
    Solution s;
    assert(s.processStr("a#b%*", 1) == 'a');
    assert(s.processStr("cd%#*#", 3) == 'd');
    assert(s.processStr("z*#", 0) == '.');
    return 0;
}
