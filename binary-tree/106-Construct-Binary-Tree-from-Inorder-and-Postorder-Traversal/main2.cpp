#include <cassert>
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
    TreeNode* buildTree_recursively(vector<int>& inorder, vector<size_t>& inorder_hash, vector<int>& postorder, int start, int end, int& node_index) {
      if (start > end) return nullptr;                                          
      TreeNode* node = new TreeNode(postorder[node_index--]);                   
      int inorder_index = inorder_hash[3000 + node->val];                       
      node->right = buildTree_recursively(inorder, inorder_hash, postorder, inorder_index + 1, end, node_index);
      node->left = buildTree_recursively(inorder, inorder_hash, postorder, start, inorder_index - 1, node_index);
      return node;                                                              
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      vector<size_t> inorder_hash(6001);                                        
      for (size_t i = 0; i < inorder.size(); ++i) inorder_hash[3000 + inorder[i]] = i;
      int node_index = inorder.size() - 1;                                      
      return buildTree_recursively(inorder, inorder_hash, postorder, 0, node_index, node_index);
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
