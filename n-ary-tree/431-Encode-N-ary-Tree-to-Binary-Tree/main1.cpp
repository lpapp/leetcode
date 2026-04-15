#include <iostream>
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    TreeNode* encode(Node* root) {
        if (!root) return nullptr;
        TreeNode* node = new TreeNode(root->val);
        if (root->children.empty()) return node;
        TreeNode* child = encode(root->children[0]);
        node->left = child;
        for (size_t i = 1; i < root->children.size(); ++i, child = child->right) child->right = encode(root->children[i]);
        return node;
    }

    Node* decode(TreeNode* root) {
        if (!root) return nullptr;
        Node* node = new Node(root->val, vector<Node*>());
        if (!root->left) return node;
        for (TreeNode* child = root->left; child; child = child->right) node->children.push_back(decode(child));
        return node;
    }
};

void printTreeNode(const TreeNode* root) {
    if (!root) { cout << "null" << endl; return; }
    cout << "val: " << root->val << endl;
    printTreeNode(root->left);
    printTreeNode(root->right);
}

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
    TreeNode* encodedNode = codec.encode(&root1);
    printTreeNode(encodedNode);
	printNode(codec.decode(encodedNode));
	return 0;
}
