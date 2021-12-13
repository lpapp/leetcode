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
    vector<int> preorderTraversal_recursive(TreeNode* root) {
      if (!root) return {};
      vector<int> values{root->val};
      vector<int> left = preorderTraversal(root->left);
      values.insert(values.end(), left.cbegin(), left.cend());
      vector<int> right = preorderTraversal(root->right);
      values.insert(values.end(), right.cbegin(), right.cend());
      return values;
    }

    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> values;
      stack<TreeNode*> s; if (root) s.push(root);
      while (!s.empty()) {
        TreeNode* top = s.top(); s.pop();
        values.push_back(top->val);
        if (top->right) s.push(top->right);
        if (top->left) s.push(top->left);
      }
      return values;
    }
};

void test(TreeNode* root)
{
  Solution s;

  cout << "[";
  for (const int e : s.preorderTraversal(root)) cout << e << ",";
  cout << "]" << endl;
}

int main()
{
  TreeNode* tree1 = new TreeNode(1);
  tree1->right = new TreeNode(2);
  tree1->right->left = new TreeNode(3);
  cout << "root = [1,null,2,3] => [1,2,3]: ";
  test(tree1);

  TreeNode* tree2 = nullptr;
  cout << "root = [] => []: ";
  test(tree2);

  TreeNode* tree3 = new TreeNode(1);
  cout << "root = [1] => [1]: ";
  test(tree3);

  TreeNode* tree4 = new TreeNode(1);
  tree4->left = new TreeNode(2);
  cout << "root = [1,2] => [1,2]: ";
  test(tree4);

  TreeNode* tree5 = new TreeNode(1);
  tree5->right = new TreeNode(2);
  cout << "root = [1,2] => [1,2]: ";
  test(tree5);

  return 0;
}
