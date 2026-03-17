#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RLEIterator {
    vector<int> m_encoding;
    size_t m_frequency_index = 0;
    int m_current_frequency_used_index = 0;
public:
    RLEIterator(vector<int>& encoding): m_encoding(encoding) {}
    int next(int n) {
         while (m_frequency_index < m_encoding.size()) {
            int current_frequency_unused = m_encoding[m_frequency_index] - m_current_frequency_used_index;
            if (current_frequency_unused < n) {
                n -= current_frequency_unused;
                m_frequency_index += 2;
                m_current_frequency_used_index = 0;
            } else {
                m_current_frequency_used_index += n;
                return m_encoding[m_frequency_index + 1];
            }
        }
        return -1;  
    }
};

int main()
{
    vector<int> encoding1 = {3, 8, 0, 9, 2, 5};
    RLEIterator* obj1 = new RLEIterator(encoding1);
    cout << obj1->next(2) << endl;
    cout << obj1->next(1) << endl;
    cout << obj1->next(1) << endl;
    cout << obj1->next(2) << endl;
    cout << endl;
	return 0;
}
