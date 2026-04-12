#include <array>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Trie {
    array<Trie*, 26> children{nullptr};
    int sum;
public:
    Trie() = default;
    void insert(string& word, int delta) {
        Trie* node = this;
        for (const char c : word) {
            const size_t index = c - 'a';
            if (!node->children[index]) node->children[index] = new Trie();
            node = node->children[index];
            node->sum += delta;
        }
    }
    int search(string& prefix) const {
        const Trie* node = this;
        for (const char c : prefix) {
            const size_t index = c - 'a';
            if (!node->children[index]) return 0;
            node = node->children[index];
        }
        return node->sum;
    }
};

class MapSum {
    unordered_map<string, int> hash;
    Trie* root;
public:
    MapSum(): root(new Trie()) {}
    void insert(string key, int val) { root->insert(key, val - hash[key]); hash[key] = val; }
    int sum(string prefix) const { return root->search(prefix); }
};

int main()
{
    MapSum* mapSum = new MapSum();
    mapSum->insert("apple", 3);  
    cout << mapSum->sum("ap") << endl;
    mapSum->insert("app", 2);    
    cout << mapSum->sum("ap") << endl;
    return 0;
}
