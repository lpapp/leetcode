#include <array>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int uniqueCharsToMatch = 0;
        array<int, 26> charFrequencyDiff = {0};
        for (const char ch : s1) {
            int charIndex = ch - 'a';
            if (++charFrequencyDiff[charIndex] == 1) ++uniqueCharsToMatch;
        }

        size_t patternLength = s1.size();
        size_t textLength = s2.size();

        for (size_t windowEnd = 0; windowEnd < textLength; ++windowEnd) {
            int currentCharIndex = s2[windowEnd] - 'a';
            if (!--charFrequencyDiff[currentCharIndex]) --uniqueCharsToMatch;
          
            if (windowEnd >= patternLength) {
                int leftCharIndex = s2[windowEnd - patternLength] - 'a';
                if (++charFrequencyDiff[leftCharIndex] == 1) ++uniqueCharsToMatch;
            }
          
            if (!uniqueCharsToMatch) return true;
        }
      
        return false;
    }
};

int main()
{
	Solution s;
    cout << s.checkInclusion("ab", "eidbaooo") << endl;
    cout << s.checkInclusion("ab", "eidboaoo") << endl;
	return 0;
}
