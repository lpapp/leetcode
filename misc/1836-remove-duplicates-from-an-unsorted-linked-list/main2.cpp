#include <iostream>

using namespace std;

struct LinkedListNode
{
    int data;
    LinkedListNode* next;
};

// N: the number of elements in the linked list.
// Time complexity: O(N^2)
// Space complexity: O(1)

class Solution {
public:
    void deleteDups(LinkedListNode* node) {
        for (LinkedListNode* current = node; current; current = current->next) {
            // Remove all future nodes that have the same value.
            LinkedListNode* runner = current;
            while (runner->next) {
                if (runner->next->data == current->data) runner->next = runner->next->next;
                else runner = runner->next;
            }
        }
    }
};

int main()
{
    Solution s;
    LinkedListNode node;
    node.data = 0;
    node.next = nullptr;
    s.deleteDups(&node);
    return 0;
}
