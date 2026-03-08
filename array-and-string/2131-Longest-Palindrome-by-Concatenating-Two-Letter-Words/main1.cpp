#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> wordFrequency;
        for (const string& word : words) ++wordFrequency[word];
        int palindromeLength = 0;
        int symmetricWordsWithOddCount = 0;
        for (const auto& [word, frequency] : wordFrequency) {
            string reversedWord = word;
            reverse(reversedWord.begin(), reversedWord.end());
            if (word[0] == word[1]) {
                symmetricWordsWithOddCount += frequency & 1;
                palindromeLength += (frequency / 2) * 2 * 2;
            } else if (wordFrequency.count(reversedWord)) {
                palindromeLength += min(frequency, wordFrequency[reversedWord]) * 2;
            }
        }
        if (symmetricWordsWithOddCount > 0) palindromeLength += 2;
        return palindromeLength;      
    }
};

int main()
{
	Solution s;
    vector<string> words1 = {"lc", "cl", "gg"};
    cout << s.longestPalindrome(words1) << endl;
    vector<string> words2 = {"ab", "ty", "yt", "lc", "cl", "ab"};
    cout << s.longestPalindrome(words2) << endl;
    vector<string> words3 = {"cc", "ll", "xx"};
    cout << s.longestPalindrome(words3) << endl;
	return 0;
}
