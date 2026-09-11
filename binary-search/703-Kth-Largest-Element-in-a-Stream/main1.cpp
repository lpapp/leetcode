#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class KthLargest {
    const size_t m_k;
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
    KthLargest kthLargest1(3, nums1);
    assert(kthLargest1.add(3) == 4);
    assert(kthLargest1.add(5) == 5);
    assert(kthLargest1.add(10) == 5);
    assert(kthLargest1.add(9) == 8);
    assert(kthLargest1.add(4) == 8);

    vector<int> nums2 = {7, 7, 7, 7, 8, 3};
    KthLargest kthLargest2(4, nums2);
    assert(kthLargest2.add(2) == 7);
    assert(kthLargest2.add(10) == 7);
    assert(kthLargest2.add(9) == 7);
    assert(kthLargest2.add(9) == 8);
    return 0;
}
