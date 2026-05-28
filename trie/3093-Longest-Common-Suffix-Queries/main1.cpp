#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Trie {
    struct Node {
        array<int, 26> children;
        int idx;
        Node() : idx(-1) { children.fill(-1); }
    };
    vector<Node> nodes{1};
    const vector<string>& words;
public:
    Trie(const vector<string>& words) : words(words) {}
    void insert(const string& word, int index) {
        int cur = 0;
        if (nodes[cur].idx == -1 || words[nodes[cur].idx].size() > word.size())
            nodes[cur].idx = index;
        for (int i = word.size() - 1; i >= 0; --i) {
            int c = word[i] - 'a';
            if (nodes[cur].children[c] == -1) {
                nodes[cur].children[c] = nodes.size();
                nodes.emplace_back();
            }
            cur = nodes[cur].children[c];
            if (nodes[cur].idx == -1 || words[nodes[cur].idx].size() > word.size())
                nodes[cur].idx = index;
        }
    }
    int query(const string& word) {
        int cur = 0;
        for (int i = word.size() - 1; i >= 0; --i) {
            int c = word[i] - 'a';
            if (nodes[cur].children[c] == -1) break;
            cur = nodes[cur].children[c];
        }
        return nodes[cur].idx;
    }
};

class Soution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie trie(wordsContainer);
        for (int i = 0, n = wordsContainer.size(); i < n; ++i) trie.insert(wordsContainer[i], i);
        vector<int> res(wordsQuery.size());
        for (int i = 0, n = wordsQuery.size(); i < n; ++i) res[i] = trie.query(wordsQuery[i]);
        return res;
    }
};

int main()
{
	Solution s;
	vector<string> wordsContainer1 = {"abcd", "bcd", "xbcd"};
	vector<string> wordsQuery1 = {"cd", "bcd", "xyz"};
	vector<int> res1 = {1, 1, 1};
	assert(s.stringIndices(wordsContainer1, wordsQuery1) == res1);
	vector<string> wordsContainer2 = {"abcdefgh", "poiuygh", "ghghgh"};
	vector<string> wordsQuery2 = {"gh", "acbfgh", "acbfegh"};
	vector<int> res2 = {2, 0, 2};
	assert(s.stringIndices(wordsContainer2, wordsQuery2) == res2);
	vector<string> wordsContainer3;
	for (int i = 0; i < 100; ++i) {
		string str(5000, 'a');
		for (int j = 1; j < 5000; j += 2) str[j] = 'a' + (i % 10);
		wordsContainer3.push_back(str);
	}
	vector<string> wordsQuery3(1000, "a");
	vector<int> res3 = s.stringIndices(wordsContainer3, wordsQuery3);
	for (int r : res3) assert(!r);
	return 0;
}
