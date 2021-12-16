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
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      if (inorder.empty()) return nullptr;

      TreeNode* node = new TreeNode(postorder[postorder.size() - 1]);
      int index = distance(inorder.begin(), find(inorder.begin(), inorder.end(), node->val));

      vector<int> left_inorder(inorder.begin(), inorder.begin() + index);
      vector<int> left_postorder(postorder.begin(), postorder.begin() + index);
      node->left = buildTree(left_inorder, left_postorder);

      vector<int> right_inorder(inorder.begin() + index, inorder.end());
      vector<int> right_postorder(postorder.begin() + index, postorder.end() - 1);
      node->right = buildTree(right_inorder, right_postorder);

      return node;
    }
};

void preorderTraversal(TreeNode* root) {
  cout << (root ? to_string(root->val) : "nullptr") << endl;
  if (!root) return;
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void test(vector<int>& inorder, vector<int>& postorder)
{
  Solution s;
  TreeNode* t = s.buildTree(inorder, postorder);
  preorderTraversal(t);
}

int main()
{
  vector<int> inorder{9, 3, 15, 20, 7};
  vector<int> postorder{9, 15, 7, 20, 3};
  cout << "inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]  => [3,9,20,null,null,15,7]: ";
  test(inorder, postorder);

  /* vector<int> inorder{-1};
  vector<int> postorder{-1};
  cout << "inorder = [-1], postorder = [-1] => [-1]: ";
  test(inorder, postorder);*/

  return 0;
}
