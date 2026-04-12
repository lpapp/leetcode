#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class TrieNode {
public:
    array<TrieNode*, 27> children{nullptr};
    int frequency;
    string sentence;
    TrieNode() = default;
    void insert(const string& sentence, int times) {
        TrieNode* node = this;
        for (const char c : sentence) {
            const size_t index = (c == ' ') ? 26 : (c - 'a');
            if (!node->children[index]) node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->frequency += times;
        node->sentence = sentence;
    }
    const TrieNode* search(const string& prefix) const {
        const TrieNode* node = this;
        for (const char c : prefix) {
            const size_t index = (c == ' ') ? 26 : (c - 'a');
            if (!node->children[index]) return nullptr;
            node = node->children[index];
        }
        return node;
    }
};

class AutocompleteSystem {
    TrieNode* root;
    string currentInput;
    static constexpr auto cmp = [](const TrieNode* a, const TrieNode* b) { return (a->frequency == b->frequency) ? (a->sentence < b->sentence) : (a->frequency > b->frequency); };
    using MinHeap = priority_queue<const TrieNode*, vector<const TrieNode*>, decltype(cmp)>;
    void dfs(const TrieNode* node, MinHeap& minHeap) {
        if (!node) return;
        if (node->frequency > 0) { minHeap.push(node); if (minHeap.size() > 3) minHeap.pop(); }
        for (size_t i = 0; i < 27; ++i) dfs(node->children[i], minHeap);
    }
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times): root(new TrieNode) { for (size_t i = 0; i < sentences.size(); ++i) root->insert(sentences[i], times[i]); }
    vector<string> input(char c) {
        vector<string> suggestions;
        if (c == '#') { root->insert(currentInput, 1); currentInput = ""; return suggestions; }
        currentInput += c;
        const TrieNode* node = root->search(currentInput);
        if (!node) return suggestions;
        MinHeap minHeap;
        dfs(node, minHeap);
        for (; !minHeap.empty(); minHeap.pop()) suggestions.insert(suggestions.begin(), minHeap.top()->sentence);
        return suggestions;
    }
};

void printVector(vector<string> input)
{
    for (const string& item : input) cout << item << ", ";
    cout << endl;
}

int main()
{
	vector<string> sentences1 = {"i love you", "island", "i love coding"};
	vector<int> times1 = {5, 3, 2};
	AutocompleteSystem* obj = new AutocompleteSystem(sentences1, times1);
	printVector(obj->input('i'));
    return 0;
}
