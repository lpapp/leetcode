#include <iostream>
#include <unordered_map>

using namespace std;

class TwoSum {
    unordered_map<int, int> hash;
public:
    TwoSum() = default;
    void add(int number) { ++hash[number]; }
    bool find(int value) {
        for (auto& [number, count] : hash) {
            const long complement = static_cast<long>(value) - number;
            if (hash.contains(complement) && (number != complement || count > 1)) return true;
        }
        return false;
    }
};

int main()
{
    TwoSum* obj = new TwoSum();
    obj->add(3);
    obj->add(5);
    obj->add(3);
    cout << obj->find(8) << endl;
    cout << obj->find(6) << endl;
    cout << obj->find(10) << endl;
	return 0;
}
