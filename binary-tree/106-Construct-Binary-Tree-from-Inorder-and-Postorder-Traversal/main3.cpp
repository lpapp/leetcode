#include <cassert>
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
    TreeNode* buildTree(int inorderStart, int postorderStart, int subtreeSize, unordered_map<int, int>& hash, vector<int>& postorder) {
        if (subtreeSize <= 0) return nullptr;
        const int rootValue = postorder[postorderStart + subtreeSize - 1];
        const int rootIndexInorder = hash[rootValue];
        const int leftSubtreeSize = rootIndexInorder - inorderStart;
        TreeNode* leftChild = buildTree(inorderStart, postorderStart, leftSubtreeSize, hash, postorder);
        const int rightSubtreeSize = subtreeSize - leftSubtreeSize - 1;
        TreeNode* rightChild = buildTree(rootIndexInorder + 1, postorderStart + leftSubtreeSize, rightSubtreeSize, hash, postorder);
        return new TreeNode(rootValue, leftChild, rightChild);
    };
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> hash;
        const int totalNodes = inorder.size();
        for (int i = 0; i < totalNodes; ++i) hash[inorder[i]] = i;
        return buildTree(0, 0, totalNodes, hash, postorder);
    }
};

int main()
{
    Solution s;
    vector<int> inorder1 = {9, 3, 15, 20, 7};
    vector<int> postorder1 = {9, 15, 7, 20, 3};
    TreeNode* res1 = s.buildTree(inorder1, postorder1);
    assert(res1->val == 3);
    assert(res1->left->val == 9);
    assert(!res1->left->left);
    assert(!res1->left->right);
    assert(res1->right->val == 20);
    assert(res1->right->left->val == 15);
    assert(!res1->right->left->left);
    assert(!res1->right->left->right);
    assert(res1->right->right->val == 7);
    assert(!res1->right->right->left);
    assert(!res1->right->right->right);

    vector<int> inorder2 = {-1};
    vector<int> postorder2 = {-1};
    TreeNode* res2 = s.buildTree(inorder2, postorder2);
    assert(res2->val == -1);
    assert(!res2->left);
    assert(!res2->right);
	return 0;
}
