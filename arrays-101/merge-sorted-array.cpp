#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      while (n > 0) {
        if (!m or nums1[m - 1] <= nums2[n - 1]) { nums1[m + n - 1] = nums2[n - 1]; --n; }
        else { nums1[m + n - 1] = nums1[m - 1]; --m; };
      }
    }
};

void test(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
  Solution s;
  s.merge(nums1, m, nums2, n);
  for (const int e : nums1) cout << e << ",";
  cout << endl;
}

int main()
{
  vector<int> M1{1, 2, 3, 0, 0, 0};
  vector<int> N1{2, 5, 6};
  cout << "[1,2,3,0,0,0] | 3 | [2,5,6] | 3 => [1,2,2,3,5,6]: ";
  test(M1, 3, N1, 3);

  vector<int> M2{1};
  vector<int> N2{};
  cout << "[1] 1 | [] | 0 => [1]: ";
  test(M2, 1, N2, 0);

  vector<int> M3{0};
  vector<int> N3{1};
  cout << "[0] | 0 | [1] | 1 => [1]: ";
  test(M3, 0, N3, 1);

  return 0;
}
