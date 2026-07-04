#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
    bool isValid(const string& s, int start, int end) {
        const int len = end - start;
        if (len > 3 || len == 0) return false;
        if (len > 1 && s[start] == '0') return false;
        if (len == 3) {
            const int val = (s[start] - '0') * 100 + (s[start + 1] - '0') * 10 + (s[start + 2] - '0');
            return val <= 255;
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        const int n = s.size();
        if (n < 4 || n > 12) return res;
        string buf; buf.reserve(n + 3);
        for (int i = 1; i < 4 && i < n; ++i)
            for (int j = i + 1; j < i + 4 && j < n; ++j)
                for (int k = j + 1; k < j + 4 && k < n; ++k) {
                    if (n - k > 3) continue;
                    if (isValid(s, 0, i) && isValid(s, i, j) && isValid(s, j, k) && isValid(s, k, n)) {
                        buf.clear();
                        buf.append(s, 0, i);
                        buf += '.';
                        buf.append(s, i, j - i);
                        buf += '.';
                        buf.append(s, j, k - j);
                        buf += '.';
                        buf.append(s, k, n - k);
                        res.push_back(buf);
                    }
                }
        return res;   
    }
};

int main()
{
    Solution s;
    vector<string> res1 = s.restoreIpAddresses("25525511135");
    vector<string> res2 = s.restoreIpAddresses("0000");
    vector<string> exp2 = {"0.0.0.0"};
    assert(res2 = exp2);
    vector<string> res3 = s.retoreIpAddresses("101023");
    return 0;
}
