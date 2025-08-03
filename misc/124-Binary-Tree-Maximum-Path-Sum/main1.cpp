#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

// Runtime Complexity: O(N) - the max is calculated for each node in the tree.
// Space complexity:   O(N) - recursion stack for each node in the tree
// N: number of nodes in the tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int maxPathSumRecursive(TreeNode* root, int& result) {
        if (!root) return 0;
        const int leftChildMaxPathSum = maxPathSumRecursive(root->left, result);
        const int rightChildMaxPathSum = maxPathSumRecursive(root->right, result);
        const int singleChildMaxPathSum = std::max(leftChildMaxPathSum, rightChildMaxPathSum);
        const int subrootMaxPathSum = root->val + std::max(singleChildMaxPathSum, 0);
        const int rootMaxPathSum = std::max(subrootMaxPathSum, root->val + leftChildMaxPathSum + rightChildMaxPathSum);
        result = std::max(result, rootMaxPathSum);
        return subrootMaxPathSum;
    }

public:
    int maxPathSum(TreeNode* root) {
        int result = std::numeric_limits<int>::min();
        maxPathSumRecursive(root, result);
        return result;
    }
};

int main()
{
    Solution* solution = new Solution();

    struct TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    std::cout << solution->maxPathSum(root1) << std::endl;

    struct TreeNode* root2 = new TreeNode(-10);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(20);
    root2->right->left = new TreeNode(15);
    root2->right->right = new TreeNode(7);
    std::cout << solution->maxPathSum(root2) << std::endl;

    return 0;
}
