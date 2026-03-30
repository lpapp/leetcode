#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    Node* dfs(Node* node, unordered_map<Node*, Node*>& hash) {
        if (!node) return nullptr;
        if (hash.contains(node)) return hash[node];
        Node* cloned = new Node(node->val);
        hash[node] = cloned;
        for (Node* neighbor : node->neighbors) cloned->neighbors.push_back(dfs(neighbor, hash));
        return cloned;
    };
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> hash;
        return dfs(node, hash); 
    }
};

void printNode(Node* node) {
    if (!node) { cout << "null" << endl; return; }
    cout << node->val << endl;
}

int main()
{
    Solution s;
    Node node1(1), node2(2), node3(3), node4(4);
    node1.neighbors = {&node2, &node4};
    node2.neighbors = {&node1, &node3};
    node3.neighbors = {&node2, &node4};
    node4.neighbors = {&node1, &node3};
    printNode(s.cloneGraph(&node1));

    Node node10(1);
    printNode(&node10);
    printNode(nullptr);
    return 0;
}
