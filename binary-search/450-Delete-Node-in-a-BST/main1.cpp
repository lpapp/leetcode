#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val > key) { root->left = deleteNode(root->left, key); return root; }
        if (root->val < key) { root->right = deleteNode(root->right, key); return root; }
      	if (!root->left) return root->right;
        if (!root->right) return root->left;
        TreeNode* successor = root->right;
        while (successor->left) successor = successor->left;
        successor->left = root->left;
        root = root->right;
        return root;       
    }
};

void printTree(TreeNode* root) {
    if (!root) { cout << "null" << endl; return; }
    cout << root->val << endl;
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    Solution s;
	TreeNode leftleft1(2);
	TreeNode leftright1(4);
	TreeNode left1(3, &leftleft1, &leftright1);
	TreeNode rightright1(7);
    TreeNode right1(6, nullptr, &rightright1);
    TreeNode root1(5, &left1, &right1);
    printTree(s.deleteNode(&root1, 3));
    printTree(s.deleteNode(&root1, 0));
    printTree(s.deleteNode(nullptr, 0));
	return 0;
}
