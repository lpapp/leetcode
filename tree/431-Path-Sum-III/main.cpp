#include <iostream>
#include <unordered_map>

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
    int pathSum(TreeNode* root, int targetSum) {
		unordered_map<int64_t, int> hash;
		return countPathsWithSum(root, targetSum, 0, hash);
    }

	int countPathsWithSum(TreeNode* node, int targetSum, int64_t runningSum, unordered_map<int64_t, int> pathCount) {
		if (!node) return 0; // Base Case

		// Count paths with sum ending at the current node.
		runningSum += node->val;
		int64_t sum = runningSum - targetSum;
		int totalPaths = pathCount[sum];

		// If runningSum equals targetSum, then one additional path starts at
		// root. Add in this path.
		if (runningSum == targetSum) ++totalPaths;

		// Increment pathCount, recurse, then decrement pathCount.
		incrementHashTable(pathCount, runningSum, 1); // Increment pathCount
		totalPaths += countPathsWithSum(node->left, targetSum, runningSum, pathCount);
		totalPaths += countPathsWithSum(node->right, targetSum, runningSum, pathCount);
		incrementHashTable(pathCount, runningSum, -1); // Decrement pathCount

		return totalPaths;
	}

	void incrementHashTable(unordered_map<int64_t, int>& hashTable, int key, int delta) {
		int newCount = hashTable[key] + delta;
		if (!newCount) hashTable.erase(key);
		hashTable[key] = newCount;
	}
};

int main()
{
    Solution solution;
    TreeNode* root = new TreeNode(1000000000);

    root->left = new TreeNode(1000000000);
    root->right = nullptr;

    root->left->left = new TreeNode(294967296);
    root->left->right = nullptr;

    root->left->left->left = new TreeNode(1000000000);
    root->left->left->right = nullptr;
    root->left->left->left->left = new TreeNode(1000000000);
    root->left->left->left->right = nullptr;
    root->left->left->left->left->left = new TreeNode(1000000000);
    cout << solution.pathSum(root, 0) << endl;
	return 0;
}
