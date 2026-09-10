#include <cassert>
#include <utility>

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
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        auto dfs = [&](this auto&& self, TreeNode* node) -> pair<int, int> {
            if (!node) return {0, 0};
            const auto [leftSum, leftCount] = self(node->left);
            const auto [rightSum, rightCount] = self(node->right);
            const int sum = leftSum + rightSum + node->val;
            const int total = leftCount + rightCount + 1;
            if (sum / total == node->val) ++count;
            return {sum, total};
        };
        dfs(root);
        return count;
    }
};

int main()
{
    Solution s;
    TreeNode leftleft1(0);
    TreeNode leftright1(1);
    TreeNode left1(8, &leftleft1, &leftright1);
    TreeNode rightright1(6);
    TreeNode right1(5, nullptr, &rightright1);
    TreeNode root1(4, &left1, &right1);
    assert(s.averageOfSubtree(&root1) == 5);
    TreeNode root2(1);
    assert(s.averageOfSubtree(&root2) == 1);
    return 0;
}
