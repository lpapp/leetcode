#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) { val = _val; }
    Node(int _val, vector<Node*> _children) { val = _val; children = _children; }
};

class Codec {
public:
    string serialize(Node* root) {
        if (!root) return {};
        queue<const Node*> q({root});
        string result = to_string(root->val) + " ";
        while (!q.empty()) {
            const Node* node = q.front(); q.pop();
            result += to_string(node->children.size()) + " ";
            for (const Node* child : node->children) { q.push(child); result += to_string(child->val) + " "; }
        }
        return result;
    }

    Node* deserialize(string data) {
        if (data.empty()) return nullptr;
        stringstream ss(data);
        string rootString; ss >> rootString;
        Node* root = new Node(stoi(rootString));
        for (queue<Node*> q({root}); !q.empty();) {
            Node* node = q.front(); q.pop();
            string countString; ss >> countString;
            for (size_t j = 0, count = stoi(countString); j < count; ++j) {
                string childString; ss >> childString;
                Node* child = new Node(stoi(childString));
                node->children.push_back(child);
                q.push(child);
            }
        }
        return root;
    }
};

void printNode(const Node* root) {
    if (!root) { cout << "null" << endl; return; }
    cout << "val: " << root->val << endl;
    for (const Node* child: root->children) printNode(child);
}

int main()
{
	Codec codec;
    Node child14(5);
    Node child15(6);
	vector<Node*> children12 = {&child14, &child15};
    Node child11(3, children12);
    Node child12(2);
    Node child13(4);
	vector<Node*> children11 = {&child11, &child12, &child13};
    Node root1(1, children11);
    string serializedData = codec.serialize(&root1);
    cout << serializedData << endl;
	printNode(codec.deserialize(serializedData));
	return 0;
}
