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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root || root->val == val) return root;
        if (root->val > val) return searchBST(root->left, val);
        return searchBST(root->right, val);
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
    printTree(s.searchBST(&root1, 2));
    printTree(s.searchBST(&root1, 5));
	return 0;
}
