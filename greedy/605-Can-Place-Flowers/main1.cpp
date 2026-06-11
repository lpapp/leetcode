#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0, size = flowerbed.size(); i < size && n > 0; ++i) {
            if (!flowerbed[i] && (!i || !flowerbed[i - 1]) && (i == size - 1 || !flowerbed[i + 1])) {
                flowerbed[i++] = 1;
                --n;
            }
        }
        return !n;
    }
};

int main()
{
	Solution s;
    vector<int> flowerbed1 = {1, 0, 0, 0, 1};
    assert(s.canPlaceFlowers(flowerbed1, 1));
    vector<int> flowerbed2 = {1, 0, 0, 0, 1};
    assert(!s.canPlaceFlowers(flowerbed2, 2));
	return 0;
}
