#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int result = 0;
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            const size_t firstIndex = s.find_first_of(ch);
            if (firstIndex == string::npos) continue;
            const size_t lastIndex = s.find_last_of(ch);
            if (lastIndex == string::npos) continue;
          
            int characterMask = 0;
            for (size_t i = firstIndex + 1; i < lastIndex; ++i) {
                int charIndex = s[i] - 'a';
                if (!((characterMask >> charIndex) & 1)) {
                    characterMask |= (1 << charIndex);
                    ++result;
                }
            }
        }
        return result;
    }
};

int main()
{
	Solution s;
    cout << s.countPalindromicSubsequence("aabca") << endl;
    cout << s.countPalindromicSubsequence("adc") << endl;
    cout << s.countPalindromicSubsequence("bbcbaba") << endl;
	return 0;
}
