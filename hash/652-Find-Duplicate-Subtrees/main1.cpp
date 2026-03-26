#include <iostream>
#include <string>
#include <unordered_map>
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
    string dfs(TreeNode* node, unordered_map<string, int>& hash, vector<TreeNode*>& result) {
        if (!node) return "#";
        string left = dfs(node->left, hash, result);
        string right = dfs(node->right, hash, result);
        string nodeString = to_string(node->val) + "," + left + "," + right;
        if (++hash[nodeString] == 2) result.push_back(node);
        return nodeString;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> hash;
        vector<TreeNode*> result;
        dfs(root, hash, result);
        return result;
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
	TreeNode leftleft1(4);
	TreeNode left1(2, &leftleft1, nullptr);
    TreeNode rightleftleft1(4);
	TreeNode rightleft1(2, &rightleftleft1, nullptr);
	TreeNode rightright1(4);
    TreeNode right1(3, &rightleft1, &rightright1);
    TreeNode root1(1, &left1, &right1);
    printVectorTree(s.findDuplicateSubtrees(&root1));

	TreeNode left2(1);
    TreeNode right2(1);
    TreeNode root2(2, &left2, &right2);
    printVectorTree(s.findDuplicateSubtrees(&root2));

	TreeNode leftleft3(3);
	TreeNode left3(2, &leftleft3, nullptr);
	TreeNode rightleft3(3);
    TreeNode right3(2, &rightleft3, nullptr);
    TreeNode root3(2, &left3, &right3);
    printVectorTree(s.findDuplicateSubtrees(&root3));
	return 0;
}
