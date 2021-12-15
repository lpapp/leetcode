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
    void top_down_max_depth(TreeNode* root, int depth, int& answer) {
      if (!root) return;
      if (!root->left and !root->right) answer = max(answer, depth);
      top_down_max_depth(root->left, depth + 1, answer);
      top_down_max_depth(root->right, depth + 1, answer);
    }

public:
    int maxDepth_top_down(TreeNode* root) {
      int answer = 0;
      top_down_max_depth(root, 1, answer);
      return answer;
    }

    // Bottom up
    int maxDepth(TreeNode* root) {
      if (!root) return 0;
      int left_depth = maxDepth(root->left);
      int right_depth = maxDepth(root->right);
      return max(left_depth, right_depth) + 1;
    }
};

int main()
{
  Solution s;

  TreeNode* tree1 = new TreeNode(3);
  tree1->left = new TreeNode(9);
  tree1->right = new TreeNode(20);
  tree1->right->left = new TreeNode(15);
  tree1->right->right = new TreeNode(7);
  cout << "root = [3,9,20,null,null,15,7] => 3: " << s.maxDepth(tree1) << endl;

  TreeNode* tree2 = new TreeNode(1);
  tree2->right = new TreeNode(2);
  cout << "root = [1,null,2] => 2: " << s.maxDepth(tree2) << endl;

  TreeNode* tree3 = nullptr;
  cout << "root = [] => 0: " << s.maxDepth(tree3) << endl;

  TreeNode* tree4 = new TreeNode(0);
  cout << "root = [0] => 1: " << s.maxDepth(tree4) << endl;

  return 0;
}
