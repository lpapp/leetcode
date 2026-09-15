#include <cassert>
#include <stack>
#include <vector>

using namespace std;

class StockSpanner {
    vector<pair<int, int>> s;
public:
    StockSpanner() = default;
    int next(int price) {
        int span = 1;
        for (; !s.empty() && s.back().first <= price; span += s.back().second, s.pop_back());
        s.emplace_back(price, span);
        return span;
    }
};

int main()
{
    StockSpanner stockSpanner;
    assert(stockSpanner.next(100) == 1);
    assert(stockSpanner.next(80) == 1);
    assert(stockSpanner.next(60) == 1);
    assert(stockSpanner.next(70) == 2);
    assert(stockSpanner.next(60) == 1);
    assert(stockSpanner.next(75) == 4);
    assert(stockSpanner.next(85) == 6);
    return 0;
}
