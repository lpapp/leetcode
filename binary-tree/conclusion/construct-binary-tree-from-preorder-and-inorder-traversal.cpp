#include <iostream>
#include <queue>
#include <stack>
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

/**
 * Definitione cout << "null" << endl;for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* buildTree_recursively(vector<int>& preorder, vector<size_t>& inorder_hash, int start, int end, int& node_index) {
      if (start > end) return nullptr;
      TreeNode* node = new TreeNode(preorder[node_index++]);
      int inorder_index = inorder_hash[3000 + node->val];
      node->left = buildTree_recursively(preorder, inorder_hash, start, inorder_index - 1, node_index);
      node->right = buildTree_recursively(preorder, inorder_hash, inorder_index + 1, end, node_index);
      return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      vector<size_t> inorder_hash(6001);
      for (size_t i = 0; i < inorder.size(); ++i) inorder_hash[3000 + inorder[i]] = i;
      int node_index = 0;
      return buildTree_recursively(preorder, inorder_hash, 0, inorder.size() - 1, node_index);
    }
};

/* void preorderTraversal(TreeNode* root) {
  cout << (root ? to_string(root->val) : "nullptr") << endl;
  if (!root) return;
  preorderTraversal(root->left);
  preorderTraversal(root->right);
} */

void levelOrder(TreeNode* root) {
  if (!root) return;
  queue<TreeNode*> q; q.push(root);
  for (int vi = 0; !q.empty(); ++vi) {
    for (size_t i = 0, qs = q.size(); i < qs; ++i) {
      TreeNode* node = q.front(); q.pop();
      cout << node->val << endl;
      if (node->left) q.push(node->left); else cout << "null" << endl;
      if (node->right) q.push(node->right); else cout << "null" << endl;
    }
  }
}

void test(vector<int>& inorder, vector<int>& postorder)
{
  Solution s;
  TreeNode* t = s.buildTree(inorder, postorder);
  // preorderTraversal(t);
  levelOrder(t);
}

int main()
{
  // 1. Node = 3
  // 2. In-order index = 1
  // 3. Left subtree: 9-9
  //   -> Node: 9 (index = 0), done
  // 4. Right subtree: 15-20-7 / 15-7-20
  //   -> Node: 20, in-order index: 3
  //   -> Left subtree: 15 (index = 2)
  //   -> Right subtree: 7 (index = 4)
  vector<int> preorder{3, 9, 20, 15, 7};
  vector<int> inorder{9, 3, 15, 20, 7};
  cout << "preorder = [3,9,20,15,7] ,inorder = [9,3,15,20,7] => [3,9,20,null,null,15,7]: " << endl;
  test(inorder, postorder);

  /* vector<int> inorder{-1};
  vector<int> postorder{-1};
  cout << "inorder = [-1], postorder = [-1] => [-1]: ";
  test(inorder, postorder);*/

  return 0;
}
