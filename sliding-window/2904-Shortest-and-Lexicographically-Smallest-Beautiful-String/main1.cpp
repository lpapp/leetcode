#include <cassert>
#include <string>

using namespace std;

class Solution {
    bool smaller(const string& s, int a, int b, int width) {
        if (b == -1) return true;
        for (int i = 0; i < width; ++i) if (s[a + i] != s[b + i]) return s[a + i] < s[b + i];
        return false;
    }
public:
    string shortestBeautifulSubstring(string s, int k) {
        const int n = s.size();
        int bestStart = -1, len = INT_MAX;
        for (int l = 0, r = 0, ones = 0; r < n; ++r) {
            ones += s[r] == '1';
            while (ones > k || (l < r && s[l] == '0')) ones -= s[l++] == '1';
            if (ones == k) {
                const int width = r - l + 1;
                if (width < len || (width == len && smaller(s, l, bestStart, width))) { len = width; bestStart = l; }
            }
        }
        return bestStart == -1 ? "" : s.substr(bestStart, len);
    }
};

int main()
{
    Solution s;
    assert(s.shortestBeautifulSubstring("100011001", 3) == "11001");
    assert(s.shortestBeautifulSubstring("1011", 2) == "11");
    assert(s.shortestBeautifulSubstring("000", 1) == "");
    return 0;
}
