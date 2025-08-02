#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
		int currentLength = 0;
		int previousLength = 0;
		int maxLength = 1; // We can always have a sequence of at least one 1
        const size_t numsSize = nums.size();
		for (size_t i = 0; i < numsSize; ++i) {
			if (nums[i]) ++currentLength; // Current bit is a 1
			else { // Current bit is a 0
				// Update to 0 (if next bit is 0) or currentLength (if next bit
				// is 1).
                previousLength = (((i+1) == numsSize) || !nums[i+1]) ? 0 : currentLength;
                currentLength = 0;
			}
            maxLength = max(previousLength + currentLength + 1, maxLength);
		}
        return maxLength;
	}
};

int main()
{
	return 0;
}
