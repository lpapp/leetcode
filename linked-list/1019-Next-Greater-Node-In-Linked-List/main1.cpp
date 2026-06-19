#include <cassert>
#include <stack>
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
    vector<int> nextLargerNodes(ListNode* head) {
    	vector<int> res;
    	stack<pair<int,int>> s;
    	for (int i = 0; head; head = head->next, ++i) {
    	    res.push_back(0);
    	    while (!s.empty() && s.top().first < head->val) {
    	        res[s.top().second] = head->val;
    	        s.pop();
    	    }
    	    s.push({head->val, i});
    	}
    	return res;       
    }
};

int main()
{

	Solution s;
	ListNode head12(5);
	ListNode head11(1, &head12);
	ListNode head10(2, &head11);
    vector<int> res1 = {5, 5, 0};
	assert(s.nextLargerNodes(&head10) == res1);
	ListNode head24(5);
	ListNode head23(3, &head24);
	ListNode head22(4, &head23);
	ListNode head21(7, &head22);
	ListNode head20(2, &head21);
    vector<int> res2 = {7, 0, 5, 5, 0};
	assert(s.nextLargerNodes(&head20) == res2);
	return 0;
}
