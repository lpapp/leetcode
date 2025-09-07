#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.cbegin(), wordList.cend());
		queue<string> q;
		q.push(beginWord);
		for (int result = 2; !q.empty(); ++result) {
			for (size_t i = 0, currentLevelSize = q.size(); i < currentLevelSize; ++i) {
                string currentWord = q.front(); q.pop();
                for (size_t charIndex = 0; charIndex < currentWord.size(); ++charIndex) {
                    const char originalChar = currentWord[charIndex];
                    for (char newChar = 'a'; newChar <= 'z'; ++newChar) {
                        currentWord[charIndex] = newChar;
                        if (!wordSet.contains(currentWord)) continue;
                        if (currentWord == endWord) return result;
                        q.push(currentWord);
                        wordSet.erase(currentWord);
                    }
                    currentWord[charIndex] = originalChar;

                }

            }
		}
		return 0;
    }
};

int main()
{
	Solution s;
	vector<string> input1 = {"hot", "dot", "dog", "lot", "log", "cog"};
	cout << s.ladderLength("hit", "cog", input1) << endl;

	vector<string> input2 = {"hot", "dot", "dog", "lot", "log"};
	cout << s.ladderLength("hit", "cog", input2) << endl;

	return 0;
}
