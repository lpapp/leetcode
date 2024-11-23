#include <cstdlib>
#include <iostream>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Runtime Complexity: O(B) for init and O(1) for pick
// Space complexity:   O(B) for init and O(1) for pick
// B: size of blocklist

class Solution {
    int allowlistSize;
    std::unordered_map<int, int> blocklistHash;

public:
    Solution(int n, std::vector<int>& blocklist) {
        allowlistSize = n - blocklist.size();
        int mapIndex = allowlistSize;
        const std::unordered_set<int> blocklistSet(blocklist.cbegin(), blocklist.cend());
	// Map the excluded items to included items outside of the N - B range,
	// where B is the size os the block list.
        for (const int blockNumber : blocklist) {
            if (blockNumber < allowlistSize) {
                while (blocklistSet.contains(mapIndex)) ++mapIndex;
                blocklistHash[blockNumber] = mapIndex++;
            }
        }
    }

    int pick() {
        std::srand(std::time(nullptr));
        const int randomNumber = std::rand() % allowlistSize;
        return blocklistHash.contains(randomNumber) ? blocklistHash[randomNumber] : randomNumber;
    }
};

int main()
{
    std::vector<int> i1{2, 3, 5};
    Solution* obj = new Solution(7, i1);
    std::cout << obj->pick() << std::endl;

    return 0;
}
