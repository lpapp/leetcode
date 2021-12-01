#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      const size_t N = nums.size();
      unordered_map<int, vector<pair<size_t, size_t>>> two_sum_hash;
      for (size_t i = 0; i < N; ++i) {
        for (size_t j = i + 1; j < N; ++j) {
          two_sum_hash[nums[i] + nums[j]].push_back(make_pair(i, j));
        }
      }

      set<vector<int>> sum_triplets;
      for (size_t i = 0; i < N; ++i) {
        const int e = nums[i];
        if (two_sum_hash.find(-e) != two_sum_hash.end()) {
          for (const pair<size_t, size_t>& p : two_sum_hash[-e]) {
            if (i != p.first and i != p.second) {
              vector<int> sum_triplet{e, nums[p.first], nums[p.second]};
              sort(sum_triplet.begin(), sum_triplet.end());
              sum_triplets.insert(sum_triplet);
            }
          }
        }
      }
      
      return vector<vector<int>>(sum_triplets.cbegin(), sum_triplets.cend());
    }
};

void test(vector<int> A)
{
  Solution s;
  cout << "[";
  for (auto triplet : s.threeSum(A)) {
    cout << "[";
    for (auto e : triplet) cout << e << ",";
    cout << "],";
  }
  cout << "]" << endl << endl;
}

int main()
{
  vector<int> A1{-1, 0, 1, 2, -1, -4};
  cout << "[-1,0,1,2,-1,-4] => [[-1,-1,2],[-1,0,1]]: ";
  test(A1);

  vector<int> A2;
  cout << "[] => []: ";
  test(A2);

  vector<int> A3{0};
  cout << "[0] => []: ";
  test(A3);

  vector<int> A4{0, 0};
  cout << "[0, 0] => []: ";
  test(A4);

  vector<int> A5{0, 0, 0};
  cout << "[0, 0, 0] => [0, 0, 0]: ";
  test(A5);

  vector<int> A6{-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
  cout << "[-1,0,1,2,-1,-4,-2,-3,3,0,4] =>\n[[-4,0,4],[-4,1,3],[-3,-1,4],[-3,0,3],[-3,1,2],[-2,-1,3],[-2,0,2],[-1,-1,2],[-1,0,1]]:\n";
  test(A6);

  return 0;
}
