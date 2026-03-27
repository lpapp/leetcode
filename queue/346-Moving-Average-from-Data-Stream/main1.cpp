#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class MovingAverage {
    vector<int> data;
    int sum{0}, count{0};
public:
    MovingAverage(int size): data(vector<int>(size)) {}
    double next(int val) { const int index = count++ % data.size(); sum += val - data[index]; data[index] = val; return static_cast<double>(sum) / min(count, static_cast<int>(data.size())); }
};

int main()
{
    MovingAverage* obj = new MovingAverage(3);
    cout << obj->next(1) << endl;
    cout << obj->next(10) << endl;
    cout << obj->next(3) << endl;
    cout << obj->next(5) << endl;
    return 0;
}
