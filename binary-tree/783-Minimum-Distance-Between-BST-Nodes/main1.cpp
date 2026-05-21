#include <algorithm>
#include <cassert>
#include <numeric>

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
    void dfs(TreeNode* node, int& res, int& prev) {
        if (!node) return;
        dfs(node->left, res, prev);
        res = min(res, node->val - prev);
        prev = node->val;
        dfs(node->right, res, prev);
    };
public:
    int minDiffInBST(TreeNode* root) {
        int res = 1 << 17, prev = -res;
        dfs(root, res, prev);
        return res;
    }
};

int main()
{
	Solution s;
    TreeNode root13(1);
    TreeNode root14(3);
	TreeNode root11(2, &root13, &root14);
	TreeNode root12(6);
	TreeNode root10(4, &root11, &root12);
	assert(s.minDiffInBST(&root10) == 1);
    TreeNode root23(12);
    TreeNode root24(49);
	TreeNode root21(0);
	TreeNode root22(48, &root23, &root24);
	TreeNode root20(1, &root21, &root22);
	assert(s.minDiffInBST(&root20) == 1);
	return 0;
}
