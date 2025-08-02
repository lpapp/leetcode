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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true; // The empty tree is always a subtree
		return subTree(root, subRoot);
    }

	bool subTree(TreeNode* root, TreeNode* subRoot) {
		if (!root) return false; // Big tree emty and subtree still not found
		else if (root->val == subRoot->val && matchTree(root, subRoot)) return true;
		return subTree(root->left, subRoot) || subTree(root->right, subRoot);
	}

	bool matchTree(TreeNode* root, TreeNode* subRoot) {
		if (!root && !subRoot) return true; // nothing left in the subtree
		else if (!root || !subRoot) return false; // exactly one tree is empty, there trees do not match
		else if (root->val != subRoot->val) return false; // data does not match
		return matchTree(root->left, subRoot->left) && matchTree(root->right, subRoot->right);
	}
};

int main()
{
	return 0;
}
