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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val < root->val) root->left = insertIntoBST(root->left, val);
        else root->right = insertIntoBST(root->right, val);
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
	TreeNode leftleft1(1);
	TreeNode leftright1(3);
	TreeNode left1(2, &leftleft1, &leftright1);
    TreeNode right1(7);
    TreeNode root1(4, &left1, &right1);
    printTree(s.insertIntoBST(&root1, 5));

	TreeNode leftleft2(10);
	TreeNode leftright2(30);
	TreeNode left2(20, &leftleft2, &leftright2);
	TreeNode rightleft2(50);
	TreeNode rightright2(70);
    TreeNode right2(60, &rightleft2, &rightright2);
    TreeNode root2(40, &left2, &right2);
    printTree(s.insertIntoBST(&root2, 25));
	return 0;
}
