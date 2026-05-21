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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        for (queue<TreeNode*> q({root}); !q.empty();) {
            const int size = q.size();
            vector<int> level(size);
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                level[(res.size() & 1) ? size - i - 1 : i] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(level);
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
    vector<vector<int>> res1 = {{3}, {20, 9}, {15, 7}};
	assert(s.zigzagLevelOrder(&root10) == res1);
    TreeNode root20(1);
    vector<vector<int>> res2 = {{1}};
	assert(s.zigzagLevelOrder(&root20) == res2);
    vector<vector<int>> res3 = {};
	assert(s.zigzagLevelOrder(nullptr) == res3);
	return 0;
}
