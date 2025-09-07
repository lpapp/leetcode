#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    vector<vector<string>> result;
    unordered_map<string, unordered_set<string>> predecessors;

    void buildPaths(vector<string>& currentPath, const string& beginWord, const string& currentWord) {
        if (currentWord == beginWord) {
            vector<string> completePath(currentPath.rbegin(), currentPath.rend());
            result.push_back(completePath);
            return;
        }

        for (const string& predecessor : predecessors[currentWord]) {
            currentPath.push_back(predecessor);
            buildPaths(currentPath, beginWord, predecessor);
            currentPath.pop_back();
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.cbegin(), wordList.cend());
        if (!wordSet.contains(endWord)) return {};
        wordSet.erase(beginWord);
        unordered_map<string, size_t> distanceMap;
        distanceMap[beginWord] = 0;
        queue<string> q; q.push(beginWord);
        bool endFound = false;
        size_t currentDistance = 0;
        while (!q.empty() && !endFound) {
            ++currentDistance;
            size_t levelSize = q.size();
            for (size_t i = 0; i < levelSize; i++) {
                string currentWord = q.front(); q.pop();
                for (size_t charIndex = 0; charIndex < currentWord.length(); ++charIndex) {
                    for (char newChar = 'a'; newChar <= 'z'; ++newChar) {
                        string transformedWord = currentWord;
                        transformedWord[charIndex] = newChar;
                        if (distanceMap.count(transformedWord)
                            && distanceMap[transformedWord] == currentDistance) {
                            predecessors[transformedWord].insert(currentWord);
                        }

                        if (!wordSet.contains(transformedWord)) continue;
                        predecessors[transformedWord].insert(currentWord);
                        wordSet.erase(transformedWord);
                        q.push(transformedWord);
                        distanceMap[transformedWord] = currentDistance;
                        if (endWord == transformedWord) endFound = true;
                    }
                }
            }
        }

        if (endFound) {
            vector<string> currentPath;
            currentPath.push_back(endWord);
            buildPaths(currentPath, beginWord, endWord);
        }

        return result;
    }
};

void printSolution(vector<vector<string>> input)
{
    cout << "[";
    for (const vector<string>& vectorItem : input) {
        cout << "[";
        for (const string& item : vectorItem) cout << item << ", ";
        cout << "]";
    }
    cout << "]";
    cout << endl;
}

int main()
{
	Solution s;
	vector<string> input1 = {"hot", "dot", "dog", "lot", "log", "cog"};
	printSolution(s.findLadders("hit", "cog", input1));

    Solution s2;
	vector<string> input2 = {"hot", "dot", "dog", "lot", "log"};
	printSolution(s2.findLadders("hit", "cog", input2));

	return 0;
}
