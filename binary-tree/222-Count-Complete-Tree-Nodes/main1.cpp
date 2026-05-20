#include <cassert>

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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lh, rh;
        TreeNode *l = root, *r = root;
        for (lh = 0; l; ++lh, l = l->left);
        for (rh = 0; r; ++rh, r = r->right);
        if (lh == rh) return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main()
{
	Solution s;
    TreeNode root13(4);
    TreeNode root14(5);
    TreeNode root15(6);
    TreeNode root11(2, &root13, &root14);
    TreeNode root12(3, &root15, nullptr);
    TreeNode root10(1, &root11, &root12);
	assert(s.countNodes(&root10) == 6);
	assert(!s.countNodes(nullptr));
    TreeNode root30(0);
    assert(s.countNodes(&root30) == 1);
	return 0;
}
