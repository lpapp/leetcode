#include <array>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        const size_t sLength = s.size();
        array<size_t, 26> last = {0};
        for (size_t i = 0; i < sLength; ++i) last[s[i] - 'a'] = i;
        string result;
        for (size_t i = 0, mask = 0; i < sLength; ++i) {
            const char c = s[i];
            const int cIndex = c - 'a';
            if ((mask >> cIndex) & 1) continue;
            for (; !result.empty() && result.back() > c && last[result.back() - 'a'] > i; result.pop_back()) mask ^= 1 << (result.back() - 'a');
            result.push_back(c);
            mask |= 1 << cIndex;
        }
        return result;
    }
};

int main()
{
	Solution s;
    cout << s.removeDuplicateLetters("bcabc") << endl;
    cout << s.removeDuplicateLetters("cbacdcbc") << endl;
	return 0;
}
