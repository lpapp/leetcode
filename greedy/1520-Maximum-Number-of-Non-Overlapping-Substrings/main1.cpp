#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int first[26], last[26];
        for (int c = 0; c < 26; ++c) first[c] = -1;
        for (int i = 0, n = s.size(); i < n; ++i) {
            const int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }
        vector<pair<int, int>> segs;
        for (int c = 0; c < 26; ++c) {
            if (first[c] == -1) continue;
            const int left = first[c];
            int right = last[c];
            bool valid = true;
            for (int i = left; i <= right; ++i) {
                const int d = s[i] - 'a';
                if (first[d] < left) { valid = false; break; }
                if (last[d] > right) right = last[d];
            }
            if (valid) segs.emplace_back(right, left);
        }
        ranges::sort(segs);
        vector<string> res;
        for (int prev = -1; const auto& [right, left] : segs) if (left > prev) { res.push_back(s.substr(left, right - left + 1)); prev = right; }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> res1 = {"e", "f", "ccc"};
    assert(s.maxNumOfSubstrings("adefaddaccc") == res1);
    vector<string> res2 = {"bb", "cc", "d"};
    assert(s.maxNumOfSubstrings("abbaccd") == res2);
    return 0;
}
