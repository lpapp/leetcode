#include <cassert>
#include <queue>
#include <vector>

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        for (queue<TreeNode*> q({root}); !q.empty();) {
            const int size = q.size();
            int64_t sum = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(static_cast<double>(sum) / size);
        }
        return res;
    }
};

int main()
{
	Solution s;
    TreeNode root13(15);
    TreeNode root14(7);
	TreeNode root11(9);
	TreeNode root12(20, &root13, &root14);
	TreeNode root10(3, &root11, &root12);
    vector<double> res1 = {3.00000, 14.50000, 11.00000};
	assert(s.averageOfLevels(&root10) == res1);
    TreeNode root23(15);
    TreeNode root24(7);
	TreeNode root21(9, &root23, &root24);
	TreeNode root22(20);
	TreeNode root20(3, &root21, &root22);
    vector<double> res2 = {3.00000, 14.50000, 11.00000};
	assert(s.averageOfLevels(&root20) == res2);
	return 0;
}
