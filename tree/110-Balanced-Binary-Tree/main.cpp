#include <algorithm>
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
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != numeric_limits<int>::min();
    }

    int checkHeight(TreeNode* root) {
        if (!root) return -1;

        const int leftHeight = checkHeight(root->left);
        if (leftHeight == numeric_limits<int>::min()) return numeric_limits<int>::min();

        const int rightHeight = checkHeight(root->right);
        if (rightHeight == numeric_limits<int>::min()) return numeric_limits<int>::min();

        const int heightDiff = leftHeight - rightHeight;
        // Found an error, pass it back.
        if (abs(heightDiff) > 1) return numeric_limits<int>::min();
        
        return max(leftHeight, rightHeight) + 1;
    }
};

int main()
{
    Solution s;
    TreeNode node(5);
    cout << s.isBalanced(&node) << endl;
    return 0;
}
