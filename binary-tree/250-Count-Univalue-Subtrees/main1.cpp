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
	bool dfs(TreeNode* node, int& count) {
	    if (!node) return true;
	    const bool left = dfs(node->left, count), right = dfs(node->right, count);
	    if (!left || !right) return false;
	    const int leftVal = node->left ? node->left->val : node->val;
	    const int rightVal = node->right ? node->right->val : node->val;
	    if (leftVal == rightVal && rightVal == node->val) { ++count; return true; }
	    return false;
	};
public:
    int countUnivalSubtrees(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }
};

int main()
{
    Solution s;
	TreeNode leftleft1(5);
	TreeNode leftright1(5);
	TreeNode left1(5, &leftleft1, &leftright1);
	TreeNode rightright1(5);
    TreeNode right1(5, nullptr, &rightright1);
    TreeNode root1(5, &left1, &right1);
	cout << s.countUnivalSubtrees(&root1) << endl;
	return 0;
}
