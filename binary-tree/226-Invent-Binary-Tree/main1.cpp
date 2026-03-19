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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        TreeNode* invertedLeft = invertTree(root->left);
        TreeNode* invertedRight = invertTree(root->right);
        root->left = invertedRight;
        root->right = invertedLeft;
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
	TreeNode left1(4);
    TreeNode right1(6);
    TreeNode root1(10, &left1, &right1);
    printTree(s.invertTree(&root1));

	TreeNode left2(1);
    TreeNode right2(3);
    TreeNode root2(2, &left2, &right2);
    printTree(s.invertTree(&root2));
	return 0;
}
