#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode* merged, *merged_head;
      for (merged = nullptr, merged_head = merged; list1 or list2;) {
        if (!list1) {
          if (!merged) { merged = list2; merged_head = merged; }
          else merged->next = list2;
          break;
        }
        else if (!list2) {
          if (!merged) { merged = list1; merged_head = merged; }
          else merged->next = list1;
          break;
        }
        else { 
          if (list1->val < list2->val) {
            if (!merged) { merged = list1; merged_head = merged; }
            else { merged->next = list1; merged = merged->next; }
            list1 = list1->next;
          }
          else {
            if (!merged) { merged = list2; merged_head = merged; }
            else { merged->next = list2; merged = merged->next; }
            list2 = list2->next;
          }
        }
      }
      return merged_head;
    }
};

void test(ListNode* list1, ListNode* list2)
{
  Solution s;

  cout << "[";
  for (ListNode* h = s.mergeTwoLists(list1, list2); h; h = h->next) cout << h->val << ",";
  cout << "]" << endl;
}

int main()
{
  ListNode* list1 = new ListNode(1);
  list1->next = new ListNode(2);
  list1->next->next = new ListNode(4);

  ListNode* list2 = new ListNode(1);
  list2->next = new ListNode(3);
  list2->next->next = new ListNode(4);
  cout << "[1,2,4] | [1,3,4] => [1,1,2,3,4,4]: ";

  test(list1, list2);

  ListNode* list1_1 = nullptr;
  ListNode* list2_1 = nullptr;
  cout << "[] | [] => []: ";
  test(list1_1, list2_1);

  ListNode* list1_2 = nullptr;
  ListNode* list2_2 = new ListNode(0);
  cout << "[] | [0] => [0]: ";
  test(list1_2, list2_2);

  ListNode* list1_3 = new ListNode(0);
  ListNode* list2_3 = nullptr;
  cout << "[0] | [] => [0]: ";
  test(list1_3, list2_3);

  ListNode* list1_4 = new ListNode(1);
  list1_4->next = new ListNode(2);
  list1_4->next->next = new ListNode(4);

  ListNode* list2_4 = new ListNode(1);
  list2_4->next = new ListNode(3);
  list2_4->next->next = new ListNode(4);
  list2_4->next->next->next = new ListNode(5);
  cout << "[1,2,4] | [1,3,4,5] => [1,1,2,3,4,4,5]: ";
  test(list1_4, list2_4);

  return 0;
}
