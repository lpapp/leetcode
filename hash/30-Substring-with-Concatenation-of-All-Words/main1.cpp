#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wordsHash;
        for (const string& word : words) ++wordsHash[word];
        vector<int> res;
        int sLength = s.length(), wordsLength = words.size(), wordLength = words[0].length();
        for (int i = 0; i < wordLength; ++i) {
            int left = i, right = i;
            unordered_map<string, int> slidingWindow;
            while (right + wordLength <= sLength) {
                string word = s.substr(right, wordLength);
                right += wordLength;
                if (!wordsHash.contains(word)) { slidingWindow.clear(); left = right; continue; }
                ++slidingWindow[word];
                while (slidingWindow[word] > wordsHash[word]) {
                    string leftWord = s.substr(left, wordLength);
                    --slidingWindow[leftWord];
                    if (!slidingWindow[leftWord]) slidingWindow.erase(leftWord);
                    left += wordLength;
                }
                if (right - left == wordsLength * wordLength) res.push_back(left);
            }
        }
        return res;
    }
};

int main()
{
	Solution s;
	vector<string> words1 = {"foo", "bar"};
	vector<int> res1 = {0, 9};
	assert(s.findSubstring("barfoothefoobarman", words1) == res1);
	vector<string> words2 = {"word", "good", "best", "word"};
	vector<int> res2 = {};
	assert(s.findSubstring("wordgoodgoodgoodbestword", words2) == res2);
	vector<string> words3 = {"bar", "foo", "the"};
	vector<int> res3 = {6, 9, 12};
	assert(s.findSubstring("barfoofoobarthefoobarman", words3) == res3);
	return 0;
}
