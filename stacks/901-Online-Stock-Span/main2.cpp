#include <cassert>
#include <stack>

using namespace std;

class StockSpanner {
    stack<pair<int, int>> s;
public:
    StockSpanner() = default;
    int next(int price) {
        int span = 1;
        for (; !s.empty() && s.top().first <= price; span += s.top().second, s.pop());
        s.emplace(price, span);
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
