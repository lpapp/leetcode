#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

class ProductOfNumbers {
    vector<int> p{1};
public:
    ProductOfNumbers() = default;
    void add(int num) { if (num) p.push_back(p.back() * num); else p.resize(1); }
    int getProduct(int k) { return k < (int)p.size() ? p.back() / p[p.size() - k - 1] : 0; }
};

int main()
{
    ProductOfNumbers productOfNumbers;
    productOfNumbers.add(3);
    productOfNumbers.add(0);
    productOfNumbers.add(2);
    productOfNumbers.add(5);
    productOfNumbers.add(4);
    assert(productOfNumbers.getProduct(2) == 20);
    assert(productOfNumbers.getProduct(3) == 40);
    assert(productOfNumbers.getProduct(4) == 0);
    productOfNumbers.add(8);
    assert(productOfNumbers.getProduct(2) == 32);
    return 0;
}
