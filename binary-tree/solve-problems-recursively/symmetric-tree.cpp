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
    bool isSymmetric_iterative(TreeNode* root) {
      vector<TreeNode*> levelNodes;
      if (root) levelNodes.push_back(root);
      while (!levelNodes.empty()) {
        for (int start = 0, end = levelNodes.size() - 1; start < end; ++start, --end) {
          if (!levelNodes[start] and !levelNodes[end]) continue;
          else if (!levelNodes[start] or !levelNodes[end] or levelNodes[start]->val != levelNodes[end]->val) return false;
        }
        vector<TreeNode*> parents = levelNodes;
        levelNodes.clear();
        for (TreeNode* parent : parents) {
          if (parent) { levelNodes.push_back(parent->left); levelNodes.push_back(parent->right); }
        }
      }
      return true;
    }

    bool isSymmetric_iterative_queue(TreeNode* root) {
      queue<TreeNode*> q; q.push(root->left); q.push(root->right);
      while (!q.empty()) {
          TreeNode* left = q.front(); q.pop();
          TreeNode* right = q.front(); q.pop();
          if (!left and !right) continue;
          if (!left or !right or left->val != right->val) return false;
          q.push(left->left); q.push(right->right); q.push(left->right); q.push(right->left);
      }
      return true;
    }

    bool isSymmetric_recursive(TreeNode* left, TreeNode* right) {
      if (!left and !right) return true;
      if (!left or !right or left->val != right->val) return false;
      return isSymmetric_recursive(left->left, right->right) and isSymmetric_recursive(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
      return isSymmetric_recursive(root->left, root->right);
    }
};

int main()
{
  Solution s;

  TreeNode* tree1 = new TreeNode(1);
  tree1->left = new TreeNode(2);
  tree1->right = new TreeNode(2);
  tree1->left->left = new TreeNode(3);
  tree1->left->right = new TreeNode(4);
  tree1->right->left = new TreeNode(4);
  tree1->right->right = new TreeNode(3);
  cout << "root = [1,2,2,3,4,4,3] => true: " << s.isSymmetric(tree1) << endl;

  TreeNode* tree2 = new TreeNode(1);
  tree2->left = new TreeNode(2);
  tree2->right = new TreeNode(2);
  tree2->left->right = new TreeNode(3);
  tree2->right->right = new TreeNode(3);
  cout << "root = [1,2,2,null,3,null,3] => false: " << s.isSymmetric(tree2) << endl;

  TreeNode* tree3 = new TreeNode(1);
  cout << "root = [1] => true: " << s.isSymmetric(tree3) << endl;

  return 0;
}
