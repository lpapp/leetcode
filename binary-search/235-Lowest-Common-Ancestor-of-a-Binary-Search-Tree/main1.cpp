#include <algorithm>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         while (true) {
            if (root->val < min(p->val, q->val)) root = root->right;
            else if (root->val > max(p->val, q->val)) root = root->left;
            else return root;
        }
    }
};

void printTree(TreeNode* root) {
    if (!root) { cout << "null" << endl; return; }
    cout << root->val << endl;
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    Solution s;
	TreeNode leftleft1(0);
	TreeNode leftrightleft1(3);
	TreeNode leftrightright1(5);
	TreeNode leftright1(4);
    leftright1.left = &leftrightleft1;
    leftright1.right = &leftrightright1;
	TreeNode left1(2);
    left1.left = &leftleft1;
    left1.right = &leftright1;
	TreeNode rightleft1(7);
	TreeNode rightright1(9);
    TreeNode right1(8);
    right1.left = &rightleft1;
    right1.right = &rightright1;
    TreeNode root1(6);
    root1.left = &left1;
    root1.right = &right1;
    TreeNode p1(2);
    TreeNode q1(8);
    printTree(s.lowestCommonAncestor(&root1, &p1, &q1));

    TreeNode p2(2);
    TreeNode q2(4);
    printTree(s.lowestCommonAncestor(&root1, &p2, &q2));

    TreeNode left3(1);
    TreeNode root3(2);
    root3.left = &left3;
    TreeNode p3(2);
    TreeNode q3(1);
    printTree(s.lowestCommonAncestor(&root3, &p3, &q3));
	return 0;
}
