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
    int res = 0;
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int l = dfs(node->left), r = dfs(node->right);
        l = node->left && node->left->val == node->val ? l + 1 : 0;
        r = node->right && node->right->val == node->val ? r + 1 : 0;
        res = max(res, l + r);
        return max(l, r);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return res;
    }
};

int main()
{
    Solution s;
    TreeNode leftleft1(1);
    TreeNode leftright1(1);
    TreeNode left1(4, &leftleft1, &leftright1);
    TreeNode rightright1(5);
    TreeNode right1(5, nullptr, &rightright1);
    TreeNode root1(5, &left1, &right1);
    assert(s.longestUnivaluePath(&root1) == 2);

    TreeNode leftleft2(4);
    TreeNode leftright2(4);
    TreeNode left2(4, &leftleft2, &leftright2);
    TreeNode rightright2(5);
    TreeNode right2(5, nullptr, &rightright2);
    TreeNode root2(1, &left2, &right2);
    assert(s.longestUnivaluePath(&root2) == 2);
    return 0;
}
