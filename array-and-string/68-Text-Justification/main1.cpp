#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for (int i = 0, n = words.size(); i < n;) {
            vector<string> lineWords = {words[i]};
            int lineLength = words[i++].size();
            for (; i < n && lineLength + 1 + static_cast<int>(words[i].size()) <= maxWidth; lineWords.push_back(words[i++])) lineLength += 1 + words[i].size();
            if (i == n || lineWords.size() == 1) {
                string left = lineWords[0];
                for (int j = 1, s = lineWords.size(); j < s; ++j) left += " " + lineWords[j];
                string rightPadding(maxWidth - left.size(), ' ');
                res.push_back(left + rightPadding);
                continue;
            }
            string justifiedLine;
            for (int j = 0, totalWordChars = lineLength - (lineWords.size() - 1), totalSpaces = maxWidth - totalWordChars, baseSpaces = totalSpaces / (lineWords.size() - 1), extraSpaces = totalSpaces % (lineWords.size() - 1), s = lineWords.size() - 1; j < s; ++j) justifiedLine += lineWords[j] + string(baseSpaces + (j < extraSpaces ? 1 : 0), ' ');
            justifiedLine += lineWords.back();
            res.push_back(justifiedLine);
        }
        return res;
    }
};

int main()
{
	Solution s;
    vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> result1 = {
        "This    is    an",
        "example  of text",
        "justification.  "
    };
    assert(s.fullJustify(words1, 16) == result1);
    vector<string> words2 = {"What", "must", "be", "acknowledgment", "shall", "be"};
    vector<string> result2 = {
		"What   must   be",
		"acknowledgment  ",
		"shall be        "
    };
    assert(s.fullJustify(words2, 16) == result2);
    vector<string> words3 = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    vector<string> result3 = {
		"Science  is  what we",
		"understand      well",
		"enough to explain to",
		"a  computer.  Art is",
		"everything  else  we",
		"do                  "
    };
    assert(s.fullJustify(words3, 20) == result3);
	return 0;
}
