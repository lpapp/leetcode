#include <algorithm>
#include <cassert>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
    	unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
    	int count = count_if(s.cbegin(), s.cbegin() + k, [&](char c) { return vowels.contains(c); });
    	int res = count;
    	for (int i = k, n = s.size(); i < n; ++i) { count += vowels.count(s[i]) - vowels.count(s[i - k]); res = max(res, count); }
    	return res;
    }
};

int main()
{
    Solution s;
    assert(s.maxVowels("abciiidef", 3) == 3);
    assert(s.maxVowels("aeiou", 2) == 2);
    assert(s.maxVowels("leetcode", 3) == 2);
    return 0;
}
