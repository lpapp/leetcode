#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int result = -1;
        for (int left = 0, right = letters.size() - 1; left <= right;) {
            const int mid = left + ((right - left) >> 1);
            if (letters[mid] > target) { result = mid; right = mid - 1; }
			else left = mid + 1;
        }
        return result == -1 ? letters.front() : letters[result];
    }
};

int main()
{
	Solution s;
    vector<char> letters1 = {'c', 'f', 'j'};
    cout << s.nextGreatestLetter(letters1, 'a') << endl;
    vector<char> letters2 = {'c', 'f', 'j'};
    cout << s.nextGreatestLetter(letters2, 'c') << endl;
    vector<char> letters3 = {'x', 'x', 'y', 'y'};
    cout << s.nextGreatestLetter(letters3, 'z') << endl;
	return 0;
}
