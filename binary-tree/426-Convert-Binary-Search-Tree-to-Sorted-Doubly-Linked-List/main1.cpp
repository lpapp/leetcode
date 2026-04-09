#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
    Node* prev;
    Node* head;
    void inorderTraversal(Node* node) {
        if (!node) return;
        inorderTraversal(node->left);
        if (prev) { prev->right = node; node->left = prev; }
        else head = node;
        prev = node;
        inorderTraversal(node->right);
    }

public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        prev = nullptr, head = nullptr;
        inorderTraversal(root);
        prev->right = head;
        head->left = prev;
        return head;
    }
};

void printNode(Node* root) {
    if (!root) { cout << "null" << endl; return; }
    printNode(root->left);
    cout << "val: " << root->val << endl;
    printNode(root->right);
}

int main()
{
    Solution s;
	Node leftleft1(1);
	Node leftright1(3);
	Node left1(2, &leftleft1, &leftright1);
    Node right1(5);
    Node root1(4, &left1, &right1);
    printNode(s.treeToDoublyList(&root1));
	return 0;
}
