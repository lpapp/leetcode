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
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createMinimalBST(nums, 0, nums.size() - 1);
    }

    TreeNode* createMinimalBST(vector<int>& nums, int start, int end) {
        if (end < start) return nullptr;

        const int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = createMinimalBST(nums, start, mid - 1);
        node->right = createMinimalBST(nums, mid + 1, end);
        return node;
    }
};

int main()
{
    Solution s;
    vector<int> nums{-10, -3, 0, 5, 9};
    s.sortedArrayToBST(nums);

    vector<int> nums2{1, 3};
    s.sortedArrayToBST(nums2);
    return 0;
}
