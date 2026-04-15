#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* result = nullptr;
        while (root) {
            if (root->val > p->val) { result = root; root = root->left; }
            else root = root->right;
        }
        return result;
    }
};

void printNode(TreeNode* root) {
    if (!root) { cout << "null" << endl; return; }
    cout << "val: " << root->val << endl;
    printNode(root->left);
    printNode(root->right);
}

int main()
{
    Solution s;
    TreeNode leftleft1(1);
    TreeNode leftrightleft1(4);
    TreeNode leftrightright1(7);
    TreeNode leftright1(6);
    leftright1.left = &leftrightleft1;
    leftright1.right = &leftrightright1;
    TreeNode left1(3);
    left1.left = &leftleft1;
    left1.right = &leftright1;
    TreeNode rightright1(14);
    TreeNode right1(10);
    right1.right = &rightright1;
    TreeNode root1(8);
    root1.left = &left1;
    root1.right = &right1;
    TreeNode p1(6);
    printNode(s.inorderSuccessor(&root1, &p1));
    return 0;
}
