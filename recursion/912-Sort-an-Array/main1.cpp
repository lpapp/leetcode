#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
    void sort(int left, int right, vector<int>& nums) {
        if (left >= right) return;
        int i = left - 1, j = right + 1;
        const int pivot = nums[(left + right) >> 1];
        while (i < j) {
            while (nums[++i] < pivot);
            while (nums[--j] > pivot);
            if (i < j) swap(nums[i], nums[j]);
        }
        sort(left, j, nums);
        sort(j + 1, right, nums);
    };
      
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(0, nums.size() - 1, nums);
        return nums;
    }
};

void printVector(vector<int> input)
{
    for (const int item : input) cout << item << ", ";
    cout << endl;
}

int main()
{
	Solution s;
	vector<int> input1 = {5, 2, 3, 1};
    printVector(s.sortArray(input1));
	vector<int> input2 = {5, 1, 1, 2, 0, 0};
    printVector(s.sortArray(input2));
	return 0;
}
