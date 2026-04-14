#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) { val = _val; }
    Node(int _val, vector<Node*> _children) { val = _val; children = _children; }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) return result;
        for (queue<Node*> q({root}); !q.empty();) {
            vector<int> nodes;
            const size_t qSize = q.size();
            for (size_t i = 0; i < qSize; ++i) {
                Node* node = q.front(); q.pop();
                nodes.push_back(node->val);
                for (Node* child : node->children) q.push(child);
            }
            result.push_back(nodes);
        }
      
        return result;
    }
};

void printVectorVector(const vector<vector<int>>& input)
{
    cout << "[";
    for (const vector<int>& v: input) {
        cout << "[";
        for (const int i: v) {
            cout << i << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
}

int main()
{
    Solution s;
    Node child14(5);
    Node child15(6);
	vector<Node*> children12 = {&child14, &child15};
    Node child11(3, children12);
    Node child12(2);
    Node child13(4);
	vector<Node*> children11 = {&child11, &child12, &child13};
    Node root1(1, children11);
    printVectorVector(s.levelOrder(&root1));

    Node child201(2);
    Node child205(6);
    Node child208(14);
	vector<Node*> children204 = {&child208};
    Node child207(11, children204);
	vector<Node*> children203 = {&child207};
    Node child206(7, children203);
	vector<Node*> children202 = {&child205, &child206};
    Node child202(3, children202);
    Node child210(12);
	vector<Node*> children206 = {&child210};
    Node child209(8, children206);
	vector<Node*> children205 = {&child209};
    Node child203(4, children205);
    Node child213(13);
	vector<Node*> children208 = {&child213};
    Node child211(9, children208);
    Node child212(10);
	vector<Node*> children207 = {&child211, &child212};
    Node child204(5, children207);
	vector<Node*> children201 = {&child201, &child202, &child203, &child204};
    Node root2(1, children201);
    printVectorVector(s.levelOrder(&root2));
	return 0;
}
