#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void duplicateZeros_temp(vector<int>& arr) {
      const size_t N = arr.size();
      vector<int> temp;
      temp.reserve(N);
      for (size_t i = 0, j = 0; j < N; ++i, ++j) {
        temp.push_back(arr[i]);
        if (!arr[i] and j < N - 1) { temp.push_back(arr[i]); ++j; }
      }
      arr = temp;
    }

    void duplicateZeros_insert(vector<int>& arr) {
      const size_t N = arr.size();
      for (size_t i = 0; i < N; ++i) {
        if (!arr[i]) { arr.insert(arr.cbegin() + i, 1, 0); ++i; }
      }
      arr.resize(N);
    }

    void duplicateZeros(vector<int>& arr) {
      int N = arr.size();
      int zero_count = 0;
      for (int i = 0; i + zero_count < N; ++i) {
        if (!arr[i]) { if (i + zero_count == N - 1) arr[N-- - 1] = 0; else ++zero_count; }
      }

      for (int j = N - 1, i = j - zero_count; i < j; --i, --j) {
        arr[j] = arr[i];
        if (!arr[i]) arr[--j] = 0;
      }
    }
};

void test(vector<int> A)
{
  static Solution S;
  S.duplicateZeros(A);
  for (const int e : A) cout << e << ",";
  cout <<endl;
}

int main()
{
  vector<int> A1{1, 0, 2, 3, 0, 4, 5, 0};
  cout << "[1,0,2,3,0,4,5,0] => [1,0,0,2,3,0,0,4]: ";
  test(A1);

  vector<int> A2{1, 2, 3};
  cout << "[1,2,3] = [1,2,3]: ";
  test(A2);

  vector<int> A3{0};
  cout << "[0] = [0]: ";
  test(A3);

  vector<int> A4{0, 0, 1, 1, 0};
  cout << "[0, 0, 1, 1, 0] = [0, 0, 0, 0, 1]: ";
  test(A4);

  vector<int> A5{0, 1, 7, 6, 0, 2, 0, 7};
  cout << "[0,1,7,6,0,2,0,7] => [0,0,1,7,6,0,0,2]: ";
  test(A5);

  vector<int> A6{8, 4, 5, 0, 0, 0, 0, 7};
  cout << "[8,4,5,0,0,0,0,7] => [8,4,5,0,0,0,0,0]: ";
  test(A6);

  return 0;
}
