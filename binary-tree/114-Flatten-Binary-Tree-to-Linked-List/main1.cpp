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
    void flatten(TreeNode* root) {
        for (TreeNode* node = root; node; node = node->right) {
            if (node->left) {
                TreeNode* rightmost = node->left;
                while (rightmost->right) rightmost = rightmost->right;
                rightmost->right = node->right;
                node->right = node->left;
                node->left = nullptr;
            }
        }       
    }
};

int main()
{
	Solution s;
	TreeNode root13(3);
	TreeNode root14(4);
	TreeNode root15(6);
	TreeNode root11(2, &root13, &root14);
	TreeNode root12(5, nullptr, &root15);
	TreeNode root10(1, &root11, &root12);
	s.flatten(&root10);
	s.flatten(nullptr);
    TreeNode root30(0);
    s.flatten(&root30);
	return 0;
}
