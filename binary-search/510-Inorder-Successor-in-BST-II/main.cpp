struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode* parent;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* node) {
        if (!node) return nullptr;

        // Found the right children -> return the leftmost node of the right subtree.
        if (node->right) return leftMostChild(node->right);

        TreeNode* q = node;
        TreeNode* x = q->parent;
        // Go up until we are on the left instead of right
        while (x && x->left != q) { q = x; x = x->parent; }
        return x;
    }

    TreeNode* leftMostChild(TreeNode* node) {
        if (!node) return nullptr;
        while (node->left) node = node->left;
        return node;
    }
};

int main()
{
    Solution s;
    TreeNode node(5);
    s.inorderSuccessor(&node);
    return 0;
}
