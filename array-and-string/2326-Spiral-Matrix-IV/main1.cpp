#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> result(m, vector<int>(n, -1));
        int row = 0, column = 0, direction = 0;
        const array<int, 5> directions = {0, 1, 0, -1, 0};
        while (true) {
            result[row][column] = head->val;
            head = head->next;
            if (!head) break;
            for (int nextRow, nextColumn;; direction = (direction + 1) % 4) {
                nextRow = row + directions[direction], nextColumn = column + directions[direction + 1];
                if (nextRow >= 0 && nextRow < m && nextColumn >= 0 && nextColumn < n && result[nextRow][nextColumn] == -1) { row = nextRow, column = nextColumn; break; }
            }
        }
        return result;
    }
};

void printVectorVector(const vector<vector<int>>& input)
{
    cout << "[";
    for (const vector<int>& v: input) {
        cout << "[";
        for (const int& i: v) {
            cout << i << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
}

int main()
{
	Solution s;
    ListNode node113(0);
    ListNode node112(5, &node113);
    ListNode node111(5, &node112);
    ListNode node110(2, &node111);
    ListNode node109(4, &node110);
    ListNode node108(9, &node109);
    ListNode node107(7, &node108);
    ListNode node106(1, &node107);
    ListNode node105(8, &node106);
    ListNode node104(6, &node105);
    ListNode node103(2, &node104);
    ListNode node102(0, &node103);
    ListNode node101(3, &node102);
    printVectorVector(s.spiralMatrix(3, 5, &node101));

    ListNode node203(2);
    ListNode node202(1, &node203);
    ListNode node201(0, &node202);
    printVectorVector(s.spiralMatrix(1, 4, &node201));
	return 0;
}
