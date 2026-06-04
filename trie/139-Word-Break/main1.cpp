#include <algorithm>
#include <array>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
    struct TrieNode {
        array<TrieNode*, 26> children{};
        bool isWord = false;
    };
    TrieNode root;
    void insert(const string& word) {
        TrieNode* node = &root;
        for (const char c : word) {
            int i = c - 'a';
            if (!node->children[i]) node->children[i] = new TrieNode();
            node = node->children[i];
        }
        node->isWord = true;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int maxLen = 0;
        for (const string& word : wordDict) {
            insert(word);
            maxLen = max(maxLen, static_cast<int>(word.size()));
        }
        const int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for (int i = n - 1; i >= 0; --i) {
            TrieNode* node = &root;
            for (int j = i; j < min(n, i + maxLen); ++j) {
                node = node->children[s[j] - 'a'];
                if (!node) break;
                if (node->isWord && dp[j + 1]) { dp[i] = true; break; }
            }
        }
        return dp[0];
    }
};

int main()
{
	Solution s;	
	vector<string> wordDict1 = {"leet", "code"};
	assert(s.wordBreak("leetcode", wordDict1));
	vector<string> wordDict2 = {"apple", "pen"};
	assert(s.wordBreak("applepenapple", wordDict2));
	vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
	assert(!s.wordBreak("catsandog", wordDict3));
	return 0;
}
