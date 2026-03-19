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
public:
    bool checkTree(TreeNode* root) {
        return root->val == root->left->val + root->right->val;
    }
};

int main()
{
    Solution s;
	TreeNode left1(4);
    TreeNode right1(6);
    TreeNode root1(10, &left1, &right1);
    cout << s.checkTree(&root1) << endl;

	TreeNode left2(3);
    TreeNode right2(1);
    TreeNode root2(5, &left2, &right2);
    cout << s.checkTree(&root2) << endl;
	return 0;
}
