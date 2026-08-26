#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string res;
        for (int l = 0, r = 0, ones = 0, n = s.size(), len = INT_MAX; r < n; ++r) {
            ones += s[r] == '1';
            while (ones > k || (l < r && s[l] == '0')) ones -= s[l++] == '1';
            if (ones == k) {
                const int width = r - l + 1;
                string cand = s.substr(l, width);
                if (width < len || (width == len && cand < res)) { len = width; res = std::move(cand); }
            }
        }
        return res;      
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
