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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q || p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main()
{
    Solution s;
	TreeNode p1left(2);
    TreeNode p1right(3);
    TreeNode p1(1, &p1left, &p1right);
	TreeNode q1left(2);
    TreeNode q1right(3);
    TreeNode q1(1, &q1left, &q1right);
	cout << s.isSameTree(&p1, &q1) << endl;

	TreeNode p2left(2);
    TreeNode p2(1, &q1left, nullptr);
    TreeNode q2right(2);
    TreeNode q2(1, nullptr, &q2right);
	cout << s.isSameTree(&p2, &q2) << endl;

	TreeNode p3left(2);
    TreeNode p3right(1);
    TreeNode p3(1, &p3left, &p3right);
	TreeNode q3left(1);
    TreeNode q3right(2);
    TreeNode q3(1, &q3left, &q3right);
	cout << s.isSameTree(&p3, &q3) << endl;
	return 0;
}
