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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;
        if (root->val > high) return trimBST(root->left, low, high);
        if (root->val < low) return trimBST(root->right, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;   
    }
};

int main()
{
    Solution s;
    TreeNode root11(0);
    TreeNode root12(2);
    TreeNode root10(1, &root11, &root12);
    TreeNode* res1 = s.trimBST(&root10, 1, 2);
    assert(res1->val == 1);
    assert(res1->left == nullptr);
    assert(res1->right->val == 2);

    TreeNode root24(1);
    TreeNode root23(2, &root24, nullptr);
    TreeNode root21(0, nullptr, &root23);
    TreeNode root22(4);
    TreeNode root20(3, &root21, &root22);
    TreeNode* res2 = s.trimBST(&root20, 1, 3);
    assert(res2->val == 3);
    assert(res2->left->val == 2);
    assert(res2->left->left->val == 1);
    assert(res2->left->right == nullptr);
    assert(res2->right == nullptr);
    return 0;
}
