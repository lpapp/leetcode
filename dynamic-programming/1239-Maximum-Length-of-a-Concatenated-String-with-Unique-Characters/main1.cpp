#include <bit>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<pair<int,int>> info;
        info.reserve(n);
        for (const string& str : arr) {
            int m = 0, bad = 0;
            for (const char c : str) {
                int b = c - 'a';
                if (m >> b & 1) { bad = 1; break; }
                m |= 1 << b;
            }
            info.emplace_back(bad ? -1 : m, bad ? 0 : std::popcount(static_cast<unsigned>(m)));
        }
        int res = 0;
        for (int sub = 0; sub < (1 << n); ++sub) {
            int combined = 0, total = 0, valid = 1;
            for (int i = 0; i < n; ++i) {
                if (!(sub >> i & 1)) continue;
                const auto [m, c] = info[i];
                if (m == -1) { valid = 0; break; }
                combined |= m;
                total += c;
            }
            if (valid && (int)std::popcount(static_cast<unsigned>(combined)) == total) res = max(res, total);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> arr1 = {"un", "iq", "ue"};
    assert(s.maxLength(arr1) == 4);
    vector<string> arr2 = {"cha", "r", "act", "ers"};
    assert(s.maxLength(arr2) == 6);
    vector<string> arr3 = {"abcdefghijklmnopqrstuvwxyz"};
    assert(s.maxLength(arr3) == 26);
    return 0;
}
