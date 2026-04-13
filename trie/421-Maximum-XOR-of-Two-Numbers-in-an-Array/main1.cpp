#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

class Trie {
public:
    array<Trie*, 2> children{nullptr};
    Trie() = default;
    void insert(int num) {
        Trie* node = this;
        for (int i = 30; i >= 0; --i) {
            const int val = (num >> i) & 1;
            if (!node->children[val]) node->children[val] = new Trie();
            node = node->children[val];
        }
    }
    int search(int num) const {
        const Trie* node = this;
        int result = 0;
        for (int i = 30; i >= 0; --i) {
            const int val = (num >> i) & 1;
            if (node->children[val ^ 1]) { result |= (1 << i); node = node->children[val ^ 1]; }
			else node = node->children[val];
        }
        return result;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        int result = 0;
        for (const int num : nums) {
            trie->insert(num);
            result = max(result, trie->search(num));
        }
        return result;
    }
};

int main()
{
    Solution s;
	vector<int> nums1 = {3, 10, 5, 25, 2, 8};
	cout << s.findMaximumXOR(nums1) << endl;
	vector<int> nums2 = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
	cout << s.findMaximumXOR(nums2) << endl;
    return 0;
}
