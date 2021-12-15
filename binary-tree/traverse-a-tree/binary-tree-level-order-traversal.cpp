#include <iostream>
#include <queue>
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
    /* vector<vector<int>> levelOrder(TreeNode* root) {
      queue q;
      vector<vector<int>> values;
      while (!q.empty()) {
        TreeNode* node = q.pop();
        vector<int> levelValues{node->val};
        node.push(node->left);
        node.push(node->right);
      }
    } */

    void levelOrder_recursive(TreeNode* root, vector<vector<int>>& values, size_t level)
    {
      if (!root) return;
      if (values.size() == level) values.push_back({root->val});
      else values[level].push_back(root->val);
      levelOrder_recursive(root->left, values, level + 1);
      levelOrder_recursive(root->right, values, level + 1);
    }

    vector<vector<int>> levelOrder_recursive_base(TreeNode* root) {
      vector<vector<int>> values;
      levelOrder_recursive(root, values, 0);
      return values;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> values;
      vector<TreeNode*> levelNodes;
      if (root) levelNodes.push_back(root);
      while (!levelNodes.empty()) {
        vector<TreeNode*> parents = levelNodes;
        levelNodes.clear();
        vector<int> levelValues;
        for (TreeNode* parent : parents) {
          levelValues.push_back(parent->val);
          if (parent->left) levelNodes.push_back(parent->left);
          if (parent->right) levelNodes.push_back(parent->right);
        }
        values.push_back(levelValues);
      }
      return values;
    }
};

void test(TreeNode* root)
{
  Solution s;

  cout << "[";
  for (const vector<int>& v : s.levelOrder(root)) {
    cout << "[";
    for (const int e : v) cout << e << ",";
    cout << "]";
  }
  cout << "]" << endl;
}

int main()
{
  TreeNode* tree1 = new TreeNode(3);
  tree1->left = new TreeNode(9);
  tree1->right = new TreeNode(20);
  tree1->right->left = new TreeNode(15);
  tree1->right->right = new TreeNode(7);
  cout << "root = [3,9,20,null,null,15,7] => [[3],[9,20],[15,7]]: ";
  test(tree1);

  TreeNode* tree3 = new TreeNode(1);
  cout << "root = [1] => [[1]]: ";
  test(tree3);

  TreeNode* tree2 = nullptr;
  cout << "root = [] => []: ";
  test(tree2);

  return 0;
}
