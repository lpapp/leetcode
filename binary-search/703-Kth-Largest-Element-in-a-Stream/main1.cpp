#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class KthLargest {
    size_t m_k;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums): m_k(k) { for (const int num : nums) add(num); }
    int add(int val) {
        pq.push(val);
        if (pq.size() > m_k) pq.pop();
        return pq.top();  
    }
};

int main()
{
    vector<int> nums1 = {4, 5, 8, 2};
    KthLargest* kthLargest1 = new KthLargest(3, nums1);
    cout << kthLargest1->add(3) << endl;
    cout << kthLargest1->add(5) << endl;
    cout << kthLargest1->add(10) << endl;
    cout << kthLargest1->add(9) << endl;
    cout << kthLargest1->add(4) << endl;
    cout << endl;

    vector<int> nums2 = {7, 7, 7, 7, 8, 3};
    KthLargest* kthLargest2 = new KthLargest(4, nums2);
    cout << kthLargest2->add(2) << endl;
    cout << kthLargest2->add(10) << endl;
    cout << kthLargest2->add(9) << endl;
    cout << kthLargest2->add(9) << endl;
	return 0;
}
