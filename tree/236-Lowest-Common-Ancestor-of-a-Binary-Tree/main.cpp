#include <optional>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct Result {
    TreeNode* node;
    bool isAncestor;
    Result(TreeNode* n, bool isAnc): node(n), isAncestor(isAnc) { }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Result result = commonAncestorHelper(root, p, q);
        return result.isAncestor ? result.node : nullptr;
    }

    Result commonAncestorHelper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return Result(nullptr, false);
        if (root == p && root == q) return Result(root, true);

        Result resultLeft = commonAncestorHelper(root->left, p, q);
        if (resultLeft.isAncestor) return resultLeft;

        Result resultRight = commonAncestorHelper(root->right, p, q);
        if (resultRight.isAncestor) return resultRight;

        if (resultLeft.node && resultRight.node) return Result(root, true);
        else if (root == p || root == q) {
            // If we are currently at p or q, and we also found one fo those
            // nodes in a subtree, then this is truly an ancestor and the flag
            // should be true.
            bool isAncestor = resultLeft.node || resultRight.node;
            return Result(root, isAncestor);
        }

        return Result(resultLeft.node ? resultLeft.node : resultRight.node, false);      
    }
};

int main()
{
    return 0;
}
