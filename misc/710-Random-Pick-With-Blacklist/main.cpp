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
    unordered_map<int, int> blocklistHash;

public:
    Solution(int n, vector<int>& blacklist) {
        allowlistSize = n - blacklist.size();
        int mapIndex = allowlistSize;
        const unordered_set<int> blocklistSet(blacklist.cbegin(), blacklist.cend());
	    // Map the excluded items to included items outside of the N - B range,
	    // where B is the size os the block list.
        for (const int blockNumber : blacklist) {
            if (blockNumber < allowlistSize) {
                while (blocklistSet.contains(mapIndex)) ++mapIndex;
                blocklistHash[blockNumber] = mapIndex++;
            }
        }
    }

    int pick() {
        const int randomNumber = rand() % allowlistSize;
        return blocklistHash.contains(randomNumber) ? blocklistHash[randomNumber] : randomNumber;
    }
};

int main()
{
    vector<int> i1{2, 3, 5};
    Solution* obj = new Solution(7, i1);
    cout << obj->pick() << endl;

    return 0;
}
