#include <algorithm>
#include <cassert>

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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        const auto dfs = [&](this auto&& dfs, TreeNode* node) -> int {
            if (!node) return 0;
            const int l = dfs(node->left);
            const int r = dfs(node->right);
            diameter = max(diameter, l + r);
            return 1 + max(l, r);
        };
        dfs(root);
        return diameter;       
    }
};

int main()
{
    Solution s;
    TreeNode root13(4);
    TreeNode root14(5);
    TreeNode root11(2, &root13, &root14);
    TreeNode root12(3);
    TreeNode root10(1, &root11, &root12);
    assert(s.diameterOfBinaryTree(&root10) == 3);
    TreeNode root21(2);
    TreeNode root20(1, &root21, nullptr);
    assert(s.diameterOfBinaryTree(&root20) == 1);
    return 0;
}
