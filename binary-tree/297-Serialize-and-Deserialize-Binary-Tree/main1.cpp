#include <iostream>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return {};
        string result;
        for (queue<TreeNode*> q({root}); !q.empty();) {
            TreeNode* current = q.front(); q.pop();
            if (current) { result += to_string(current->val) + " "; q.push(current->left); q.push(current->right); }
            else result += "# ";
        }
        result.pop_back();
        return result;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        stringstream stringStream(data);
        string token;
        stringStream >> token;
        TreeNode* root = new TreeNode(stoi(token));
        for (queue<TreeNode*> q({root}); !q.empty();) {
            TreeNode* parent = q.front(); q.pop();
            stringStream >> token;
            if (token != "#") { parent->left = new TreeNode(stoi(token)); q.push(parent->left); }
            stringStream >> token;
            if (token != "#") { parent->right = new TreeNode(stoi(token)); q.push(parent->right); }
        }
        return root;
    }
};

void printNode(TreeNode* root) {
    if (!root) { cout << "null" << endl; return; }
    cout << "val: " << root->val << endl;
    printNode(root->left);
    printNode(root->right);
}

int main()
{
    Codec ser, deser;
    TreeNode left1(2);
    TreeNode rightleft1(4);
    TreeNode rightright1(5);
    TreeNode right1(3);
    right1.left = &rightleft1;
    right1.right = &rightright1;
    TreeNode root1(1);
    root1.left = &left1;
    root1.right = &right1;
    TreeNode* ans1 = deser.deserialize(ser.serialize(&root1));
    printNode(ans1);
    TreeNode* ans2 = deser.deserialize(ser.serialize(nullptr));
    printNode(ans2);
	return 0;
}
