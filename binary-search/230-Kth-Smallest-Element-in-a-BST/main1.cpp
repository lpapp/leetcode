#include <cassert>
#include <stack>

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
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> s;
        for (TreeNode* node = root; node || !s.empty();) {
            if (node) { s.push(node); node = node->left; } 
            else { node = s.top(); s.pop(); if (!--k) return node->val; node = node->right; }
        }
        return 0;
    }
};

int main()
{
	Solution s;
    TreeNode node13(2);
    TreeNode node11(1, nullptr, &node13);
    TreeNode node12(4);
    TreeNode node10(3, &node11, &node12);
    assert(s.kthSmallest(&node10, 1) == 1);
    TreeNode node25(1);
    TreeNode node23(2, &node25, nullptr);
    TreeNode node24(4);
    TreeNode node21(3, &node23, &node24);
    TreeNode node22(6);
    TreeNode node20(5, &node21, &node22);
    assert(s.kthSmallest(&node20, 3) == 3);
	return 0;
}
