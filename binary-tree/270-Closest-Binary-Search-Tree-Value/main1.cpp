#include <cstdlib>
#include <cmath>
#include <iostream>
#include <limits>

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
        void dfs(TreeNode* node, double target, int& val, double& min) {
            if (!node) return;
            const double diff = abs(node->val - target);
            if (diff < min || (diff == min && node->val < val)) { min = diff; val = node->val; }
            dfs((target < node->val) ? node->left : node->right, target, val, min);
        };
public:
    int closestValue(TreeNode* root, double target) {
        int val = root->val;
        double min = numeric_limits<int>::max();
        dfs(root, target, val, min);
        return val;
    }
};

int main()
{
    Solution s;
	TreeNode leftleft1(1);
	TreeNode leftright1(4);
	TreeNode left1(3, &leftleft1, &leftright1);
	TreeNode rightright1(9);
    TreeNode right1(7, nullptr, &rightright1);
    TreeNode root1(5, &left1, &right1);
    cout << s.closestValue(&root1, 4.2) << endl;
    cout << s.closestValue(&root1, 4.5) << endl;
	return 0;
}
