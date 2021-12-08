#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum_binary_search(vector<int>& numbers, int target) {
      for (int i = 0, N = numbers.size(); i < N; ++i) {
        for (int start = i + 1, end = N - 1, mid = (start + end) / 2, sum = numbers[i] + numbers[mid]; start <= end; mid = (start + end) / 2, sum = numbers[i] + numbers[mid]) {
          if (sum == target) return vector<int>{i + 1, mid + 1};
          else if (sum < target) start = mid + 1;
          else end = mid - 1;
        }
      }
      return {};
    }

    vector<int> twoSum_vector_hash(vector<int>& numbers, int target) {
      const int N = numbers.size();
      vector<vector<int>> numbers_hash(2001, vector<int>());
      for (int i = 0; i < N; ++i) {
        vector<int>& indices = numbers_hash[numbers[i] + 1000];
        if (indices.size() < 2) indices.push_back(i + 1);
      }

      for (int i = 0; i < N; ++i) {
        const vector<int>& indices = numbers_hash[target - numbers[i] + 1000];
        if (!indices.empty()) {
          if (indices[0] != i + 1) return vector<int>{i + 1, indices[0]};
          else if (indices.size() == 2) return vector<int>{i + 1, indices[1]};
        }
      }
      return {};
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
      const int N = numbers.size();
      unordered_map<int, vector<int>> numbers_hash;
      for (int i = 0; i < N; ++i) {
        vector<int>& indices = numbers_hash[numbers[i]];
        if (indices.size() < 2) indices.push_back(i + 1);
      }

      for (int i = 0; i < N; ++i) {
        const vector<int>& indices = numbers_hash[target - numbers[i]];
        if (!indices.empty()) {
          if (indices[0] != i + 1) return vector<int>{i + 1, indices[0]};
          else if (indices.size() == 2) return vector<int>{i + 1, indices[1]};
        }
      }
      return {};
    }
};

void test(vector<int>& numbers, int target)
{
  Solution s;

  cout << "[";
  for (const int e : s.twoSum(numbers, target)) cout << e << ",";
  cout << "]" << endl;
}

int main()
{
  vector<int> A1{2, 7, 11, 15};
  cout << "[2,7,11,15] | 9 => [1,2]: ";
  test(A1, 9);

  vector<int> A2{2, 3, 4};
  cout << "[2,3,4] | 6 => [1,3]: ";
  test(A2, 6);

  vector<int> A3{-1, 0};
  cout << "[-1,0] | -1 => [1,2]: ";
  test(A3, -1);

  vector<int> A4{-500, -500, -500};
  cout << "[-500,-500,-500] | -1000 => [1,2]: ";
  test(A4, -1000);

  vector<int> A5{-1000, -1, 0, 1};
  cout << "[-1000,-1,0,1] | 1 => [3,4]: ";
  test(A5, 1);

  return 0;
}
