#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
	bool match(const string& word, const string& pattern) {
    	array<int, 128> wordCharMapping = {0};
        array<int, 128> patternCharMapping = {0};
          
        for (size_t i = 0; i < word.size(); ++i) {
            const char wordChar = word[i];
            const char patternChar = pattern[i];
            if (wordCharMapping[wordChar] != patternCharMapping[patternChar]) return false;
            wordCharMapping[wordChar] = i + 1;
            patternCharMapping[patternChar] = i + 1;
        }
        
        return true;
    };

public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for (const string& word : words) {
            if (match(word, pattern)) result.push_back(word);
        }
      
        return result;   
    }
};

void printVector(vector<string> input)
{
    for (const string& item : input) cout << item << ", ";
    cout << endl;
}

int main()
{
	Solution s;
    vector<string> words1{"abc", "deq", "mee", "aqq", "dkd", "ccc"};
	string pattern1 = "abb";
    printVector(s.findAndReplacePattern(words1, pattern1));
    vector<string> words2{"a", "b", "c"};
	string pattern2 = "a";
    printVector(s.findAndReplacePattern(words2, pattern2));
	return 0;
}
