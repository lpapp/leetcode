#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int total = 0;
        for (const char c : s) total += (c != '-');
        if (total == 0) return "";
        const int firstGroup = total % k ? total % k : k;
        string res;
        res.reserve(total + (total - 1) / k);
        int count = firstGroup;
        for (const char c : s) {
            if (c == '-') continue;
            if (!count) {
                res += '-';
                count = k;
            }
            res += toupper(c);
            --count;
        }
        return res;
    }
};

int main()
{
    Solution s;
    assert(s.licenseKeyFormatting("5F3Z-2e-9-w", 4) == "5F3Z-2E9W");
    assert(s.licenseKeyFormatting("2-5g-3-J", 2) == "2-5G-3J");
    return 0;
}
