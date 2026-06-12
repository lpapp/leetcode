#include <cassert>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};

int main()
{
    Solution s;
    assert(s.gcdOfStrings("ABCABC", "ABC") == "ABC");
    assert(s.gcdOfStrings("ABABAB", "ABAB") == "AB");
    assert(s.gcdOfStrings("LEET", "CODE") == "");
    assert(s.gcdOfStrings("AAAAAB", "AAA") == "");
    return 0;
}
