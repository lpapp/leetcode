#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        const int n = word1.size(), m = word2.size();
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1, j = m - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1];
            if (j >= 0 && word1[i] == word2[j]) { ++suffix[i]; --j; }
        }
        vector<int> res; res.reserve(m);
        bool used = false;
        for (int i = 0, j = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j]) { res.push_back(i); ++j; }
            else if (!used && suffix[i + 1] >= m - j - 1) { res.push_back(i); ++j; used = true; }
        }
        return int(res.size()) == m ? res : vector<int>{};
    }
};

int main()
{
    Solution s;
    vector<int> res1 = {0, 1, 2};
    assert(s.validSequence("vbcca", "abc") == res1);
    vector<int> res2 = {1, 2, 4};
    assert(s.validSequence("bacdc", "abc") == res2);
    vector<int> res3 = {};
    assert(s.validSequence("aaaaaa", "aaabc") == res3);
    vector<int> res4 = {0, 1};
    assert(s.validSequence("abc", "ab") == res4);
    return 0;
}
