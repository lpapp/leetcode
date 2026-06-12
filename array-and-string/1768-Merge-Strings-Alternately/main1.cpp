#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        const int n1 = word1.size(), n2 = word2.size(), minLen = min(n1, n2);
        string res; res.reserve(n1 + n2);
        for (int i = 0; i < minLen; ++i) { res += word1[i]; res += word2[i]; }
        res.append(word1, minLen, n1 - minLen);
        res.append(word2, minLen, n2 - minLen);
        return res;
    }
};

int main()
{
    Solution s;
    assert(s.mergeAlternately("abc", "pqr") == "apbqcr");
    assert(s.mergeAlternately("ab", "pqrs") == "apbqrs");
    assert(s.mergeAlternately("abcd", "pq") == "apbqcd");
    return 0;
}
