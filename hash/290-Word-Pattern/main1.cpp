#include <cassert>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream stringStream(s);
        vector<string> words;
        string word;
        while (stringStream >> word) words.push_back(word);
        if (pattern.size() != words.size()) return false;
        unordered_map<char, string> letterWordHash;
        unordered_map<string, char> wordLetterHash;
        for (size_t i = 0; i < words.size(); ++i) {
            char c = pattern[i];
            string word = words[i];
            if ((letterWordHash.contains(c) && letterWordHash[c] != word) || (wordLetterHash.contains(word) && wordLetterHash[word] != c)) return false;
            letterWordHash[c] = word;
            wordLetterHash[word] = c;
        }
        return true;
    }
};

int main()
{
	Solution s;
    assert(s.wordPattern("abba", "dog cat cat dog"));
    assert(!s.wordPattern("abba", "dog cat cat fish"));
    assert(!s.wordPattern("aaaa", "dog cat cat dog"));
	return 0;
}
