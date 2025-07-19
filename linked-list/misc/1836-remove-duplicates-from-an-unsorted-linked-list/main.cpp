#include <iostream>
#include <unordered_set>

using namespace std;

struct LinkedListNode
{
    int data;
    LinkedListNode* next;
};

// N: the number of elements in the linked list.
// Time complexity: O(N)
// Space complexity: O(N)

class Solution {
public:
    void deleteDups(LinkedListNode* node) {
        unordered_set<int> nodeSet;
        for (LinkedListNode* previous = nullptr; node; node = node->next) {
            if (nodeSet.contains(node->data)) previous->next = node->next;
            else { nodeSet.insert(node->data); previous = node; }
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
