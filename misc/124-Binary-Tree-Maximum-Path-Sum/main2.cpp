#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <stack>
#include <utility>

using namespace std;

// Runtime Complexity: O(N) - the max is calculated for each node in the tree.
// Space complexity:   O(H) - recursion stack for each height in the tree as doing DFS.
// N: number of nodes in the tree
// H: The height of the tree

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
    int maxPathSum(TreeNode* root) {
        int result = std::numeric_limits<int>::min();
        std::stack<std::pair<TreeNode*, int>> s;
        s.push(std::make_pair(root, 0));
        while (!s.empty()) {
            TreeNode* node = s.top().first;
            const int state = s.top().second;
            s.pop();
            if (!node) continue;
            switch (state) {
            case 0:
                s.push(std::make_pair(node, 1));
                s.push(std::make_pair(node->left, 0));
                break;
            case 1:
                s.push(std::make_pair(node, 2));
                s.push(std::make_pair(node->right, 0));
                break;
            case 2: {
                const int leftChildSum = node->left ? node->left->val : 0;
                const int rightChildSum = node->right ? node->right->val : 0;
                result = std::max(result, node->val + std::max(leftChildSum, 0) + std::max(rightChildSum, 0));
                const int maxChildSum = std::max(leftChildSum, rightChildSum);
                node->val += max(maxChildSum, 0);
                }
                break;
            default:
                assert(false && "Invalid status"); 
                break;
            }
        }
        return result;
    }
};

int main()
{
    Solution* solution = new Solution();

    struct TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    cout << solution->maxPathSum(root1) << endl;

    struct TreeNode* root2 = new TreeNode(-10);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(20);
    root2->right->left = new TreeNode(15);
    root2->right->right = new TreeNode(7);
    cout << solution->maxPathSum(root2) << endl;

    return 0;
}
