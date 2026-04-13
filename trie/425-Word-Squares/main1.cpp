#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;



int main()
{
    Solution s;
    vector<string> dictionary1 = {"cat", "bat", "rat"};
    cout << s.replaceWords(dictionary1, "the cattle was rattled by the battery") << endl;
    vector<string> dictionary2 = {"a", "b", "c"};
    cout << s.replaceWords(dictionary2, "aadsfasf absbs bbab cadsfafs") << endl;
    return 0;
}
