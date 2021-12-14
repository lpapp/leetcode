#include <iostream>
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
    vector<int> inorderTraversal_recursive(TreeNode* root) {
      if (!root) return {};
      vector<int> values;
      vector<int> left = inorderTraversal_recursive(root->left);
      values.insert(values.end(), left.cbegin(), left.cend());
      values.push_back(root->val);
      vector<int> right = inorderTraversal_recursive(root->right);
      values.insert(values.end(), right.cbegin(), right.cend());
      return values;
    }

    vector<int> inorderTraversal_iterative(TreeNode* root) {
      vector<int> values;
      stack<TreeNode*> s;
      for (TreeNode* node = root; node or !s.empty(); node = node->right) {
        for (; node; node = node->left) s.push(node);
        node = s.top(); s.pop();
        values.push_back(node->val);
      }
      return values;
    }

    // Morris traversal (threaded binary tree) without stack or recursion.
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> values;
      for (TreeNode* node = root; node;) {
        if (node->left) {
          TreeNode* left;
          for (left = node->left; left->right; left = left->right);
          left->right = node;
          TreeNode* temp = node;
          node = node->left;
          temp->left = nullptr;
        } else {
          values.push_back(node->val);
          node = node->right;
        }
      }
      return values;
    }
};

void test(TreeNode* root)
{
  Solution s;

  cout << "[";
  for (const int e : s.inorderTraversal(root)) cout << e << ",";
  cout << "]" << endl;
}

int main()
{
  TreeNode* tree1 = new TreeNode(1);
  tree1->right = new TreeNode(2);
  tree1->right->left = new TreeNode(3);
  cout << "root = [1,null,2,3] => [1,3,2]: ";
  test(tree1);

  TreeNode* tree2 = nullptr;
  cout << "root = [] => []: ";
  test(tree2);

  TreeNode* tree3 = new TreeNode(1);
  cout << "root = [1] => [1]: ";
  test(tree3);

  TreeNode* tree4 = new TreeNode(1);
  tree4->left = new TreeNode(2);
  cout << "root = [1,2] => [2,1]: ";
  test(tree4);

  TreeNode* tree5 = new TreeNode(1);
  tree5->right = new TreeNode(2);
  cout << "root = [1,2] => [1,2]: ";
  test(tree5);

  return 0;
}
