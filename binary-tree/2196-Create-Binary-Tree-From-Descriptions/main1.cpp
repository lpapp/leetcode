#include <cassert>
#include <unordered_map>
#include <unordered_set>
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
		for (const vector<int>& description : descriptions) {
            const int parentVal = description[0]; int childVal = description[1];
            const bool left = description[2];
            if (!nodes.contains(parentVal)) nodes[parentVal] = new TreeNode(parentVal);
            if (!nodes.contains(childVal)) nodes[childVal] = new TreeNode(childVal);
            if (left) nodes[parentVal]->left = nodes[childVal];
            else nodes[parentVal]->right = nodes[childVal];
            children.insert(childVal);
        }
        for (const auto& [nodeVal, node] : nodes) if (!children.contains(nodeVal)) return node;
        return nullptr;
    }
};

int main()
{
	Solution s;
    vector<vector<int>> descriptions1 = {
            {20, 15, 1},
            {20, 17, 0},
            {50, 20, 1},
            {50, 80, 0},
            {80, 19, 1}
    };
    TreeNode* tree = s.createBinaryTree(descriptions1);
    assert(tree->val == 50);
    assert(tree->left->val == 20);
    assert(tree->right->val == 80);
    assert(tree->left->left->val == 15);
    assert(tree->left->right->val == 17);
    assert(tree->right->left->val == 19);
    vector<vector<int>> descriptions2 = {
            {1, 2, 1},
            {2, 3, 0},
            {3, 4, 1}
    };
    tree = s.createBinaryTree(descriptions2);
    assert(tree->val == 1);
    assert(tree->left->val == 2);
    assert(tree->left->right->val == 3);
    assert(tree->left->right->left->val == 4);
	return 0;
}
