#include <iostream>

using namespace std;

class ArrayReader {
    public:
        int get(int index) const { return index; }
};

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int right = 1;
        while (reader.get(right) < target) right <<= 1;
        int left = right >> 1;
        int result = -1;
        while (left <= right) {
            const int mid = left + ((right - left) >> 1);
            if (reader.get(mid) >= target) { result = mid; right = mid - 1; }
            else left = mid + 1;
        }
        if (result != -1 && reader.get(result) == target) return result;
        return -1;
    }
};

int main()
{
	Solution s;
    ArrayReader a;
    cout << s.search(a, 9) << endl;
	return 0;
}
