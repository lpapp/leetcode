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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q({root});
        while (!q.empty()) {
            for (int i = 0, size = q.size(); i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                if (i == size - 1) res.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};

int main()
{
	Solution s;
    TreeNode root13(5);
    TreeNode root14(4);
    TreeNode root11(2, nullptr, &root13);
    TreeNode root12(3, nullptr, &root14);
    TreeNode root10(1, &root11, &root12);
    vector<int> res1 = {1, 3, 4};
	assert(s.rightSideView(&root10) == res1);
    TreeNode root24(5);
    TreeNode root23(4, &root24, nullptr);
    TreeNode root21(2, &root23, nullptr);
    TreeNode root22(3);
    TreeNode root20(1, &root21, &root22);
    vector<int> res2 = {1, 3, 4, 5};
	assert(s.rightSideView(&root20) == res2);
    TreeNode root31(3);
    TreeNode root30(1, nullptr, &root31);
    vector<int> res3 = {1, 3};
	assert(s.rightSideView(&root30) == res3);
    vector<int> res4 = {};
	assert(s.rightSideView(nullptr) == res4);
	return 0;
}
