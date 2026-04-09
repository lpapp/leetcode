#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        for (queue<Node*> q({root}); !q.empty();) {
            Node* previous = nullptr;
            for (size_t i = 0, levelSize = q.size(); i < levelSize; ++i) {
                Node* current = q.front(); q.pop();
                if (previous) previous->next = current;
                previous = current;
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
        }
        return root;
    }
};

void printNode(Node* root) {
    if (!root) { cout << "null" << endl; return; }
    cout << "val: " << root->val << ", next: ";
	if (root->next) cout << root->next->val << endl;
	else cout << "NULL" << endl;
    printNode(root->left);
    printNode(root->right);
}

int main()
{
    Solution s;
	Node leftleft1(4);
	Node leftright1(5);
	Node left1(2, &leftleft1, &leftright1, nullptr);
	Node rightright1(7);
    Node right1(3, nullptr, &rightright1, nullptr);
    Node root1(1, &left1, &right1, nullptr);
    printNode(s.connect(&root1));
    printNode(s.connect(nullptr));
	return 0;
}
