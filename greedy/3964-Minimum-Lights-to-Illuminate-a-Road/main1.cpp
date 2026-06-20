#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int minLights(vector<int>& lights) {
        const int n = lights.size();
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            if (lights[i] <= 0) continue;
            ++diff[max(0, i - lights[i])];
            --diff[min(n, i + lights[i] + 1)];
        }
        int res = 0;
        for (int sum = 0, i = 0, cover = -1; i < n; ++i) {
            sum += diff[i];
            if (sum > 0 || i <= cover) continue;
            ++res;
            cover = i + 2;
        }
        return res;
    }
};

int main()
{
	Solution s;
    vector<int> lights1 = {0, 0, 0, 0};
    assert(s.minLights(lights1) == 2);
    vector<int> lights2 = {0, 0, 0, 2, 0};
    assert(s.minLights(lights2) == 1);
	return 0;
}
