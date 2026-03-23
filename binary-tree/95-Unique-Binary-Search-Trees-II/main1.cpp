#include <iostream>
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
    vector<TreeNode*> generateSubtrees(size_t start, size_t end) {
        if (start > end) return vector<TreeNode*>{nullptr};
        vector<TreeNode*> result;
        for (size_t i = start; i <= end; ++i) {
            vector<TreeNode*> lefts = generateSubtrees(start, i - 1);
            vector<TreeNode*> rights = generateSubtrees(i + 1, end);
            for (TreeNode* left : lefts) {
                for (TreeNode* right : rights) result.push_back(new TreeNode(i, left, right));
            }
        }
        return result;
    };
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateSubtrees(1, n);
    }
};

void printTree(TreeNode* root) {
    if (!root) { cout << "null" << endl; return; }
    cout << root->val << endl;
    printTree(root->left);
    printTree(root->right);
}

void printVectorTree(const vector<TreeNode*>& trees)
{
    for (TreeNode* tree : trees) {
        printTree(tree);
        cout << endl;
    }
}

int main()
{
    Solution s;
    printVectorTree(s.generateTrees(3));
    printVectorTree(s.generateTrees(1));
	return 0;
}
