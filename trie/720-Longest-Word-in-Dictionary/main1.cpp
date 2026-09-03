#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
    struct Node { int ch[26] = {}; bool end = false; };
    vector<Node> t{Node{}};
public:
    string longestWord(vector<string>& words) {
        for (const string& word : words) {
            int cur = 0;
            for (const char c : word) {
                const int i = c - 'a';
                if (!t[cur].ch[i]) { t.push_back(Node{}); t[cur].ch[i] = t.size() - 1; }
                cur = t[cur].ch[i];
            }
            t[cur].end = true;
        }
        string res;
        for (const string& word : words) {
            int cur = 0;
            bool ok = true;
            for (const char c : word) {
                const int i = c - 'a';
                if (!t[cur].ch[i] || !t[t[cur].ch[i]].end) { ok = false; break; }
                cur = t[cur].ch[i];
            }
            if (ok && (word.size() > res.size() || (word.size() == res.size() && word < res))) res = word;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> words1 = {"w", "wo", "wor", "worl", "world"};
    assert(s.longestWord(words1) == "world");
    vector<string> words2 = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    assert(s.longestWord(words2) == "apple");
    return 0;
}
