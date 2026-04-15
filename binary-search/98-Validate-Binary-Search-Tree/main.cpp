#include <iostream>
#include <optional>

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
    bool isValidBST(TreeNode* root) {
        return checkBST(root, nullopt, nullopt);
    }

    bool checkBST(TreeNode* node, optional<int> min, optional<int> max) {
        if (!node) return true;
        if ((min && node->val <= *min) || (max && node->val >= max)) return false;
        if (!checkBST(node->left, min, node->val) || !checkBST(node->right, node->val, max)) return false;
        return true;
    }
};

int main()
{
    Solution s;
    TreeNode left1(1);
    TreeNode right1(3);
    TreeNode root1(2, &left1, &right1);
    cout << "Actual: " << s.isValidBST(&root1) << ", Expected: " << true << endl;

    TreeNode rightleft2(3);
    TreeNode rightright2(6);
    TreeNode right2(4, &rightleft2, &rightright2);
    TreeNode left2(1);
    TreeNode root2(5, &left2, &right2);
    cout << "Actual: " << s.isValidBST(&root2) << ", Expected: " << false << endl;

    TreeNode left3(2);
    TreeNode right3(2);
    TreeNode root3(2, &left3, &right3);
    cout << "Actual: " << s.isValidBST(&root3) << ", Expected: " << false << endl;
    return 0;
}
