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
    int dfs(TreeNode* node, int sum) {
        if (!node) return 0;
        sum = sum * 10 + node->val;
        if (!node->left && !node->right) return sum;
        return dfs(node->left, sum) + dfs(node->right, sum);
    };
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);   
    }
};

int main()
{
	Solution s;
	TreeNode root11(2);
	TreeNode root12(3);
	TreeNode root10(1, &root11, &root12);
	assert(s.sumNumbers(&root10) == 25);
    TreeNode root23(5);
    TreeNode root24(1);
    TreeNode root21(9, &root23, &root24);
    TreeNode root22(0);
    TreeNode root20(4, &root21, &root22);
	assert(s.sumNumbers(&root20) == 1026);
	return 0;
}
