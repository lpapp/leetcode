#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class BSTIterator {
    TreeNode* currentNode;
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root): currentNode(root) { }
    int next() {
        for (;currentNode; currentNode = currentNode->left) s.push(currentNode);
        const TreeNode* node = s.top(); s.pop();
        currentNode = node->right;
        return node->val;
    }
    bool hasNext() { return currentNode || !s.empty(); }
};

int main()
{
    TreeNode left1(3);
    TreeNode rightleft1(9);
    TreeNode rightright1(20);
    TreeNode right1(15, &rightleft1, &rightright1);
    TreeNode root1(7, &left1, &right1); 
    BSTIterator* it = new BSTIterator(&root1);
    cout << it->next() << endl;
    cout << it->next() << endl;
    cout << it->hasNext() << endl;
    cout << it->next() << endl;
    cout << it->hasNext() << endl;
    cout << it->next() << endl;
    cout << it->hasNext() << endl;
    cout << it->next() << endl;
    cout << it->hasNext() << endl;
    return 0;
}
