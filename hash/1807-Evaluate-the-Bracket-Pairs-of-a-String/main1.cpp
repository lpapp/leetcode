#include <cassert>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string_view, string_view> dict;
        dict.reserve(knowledge.size());
        for (const vector<string>& kv : knowledge) dict.emplace(kv[0], kv[1]);
        const int n = s.size();
        string res; res.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] != '(') { res += s[i]; continue; }
            const int close = s.find(')', i + 1);
            const string_view key(s.data() + i + 1, close - i - 1);
            const auto it = dict.find(key);
            res += it == dict.end() ? string_view("?") : it->second;
            i = close;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> knowledge1 = {{"name", "bob"}, {"age", "two"}};
    assert(s.evaluate("(name)is(age)yearsold", knowledge1) == "bobistwoyearsold");
    vector<vector<string>> knowledge2 = {{"a", "b"}};
    assert(s.evaluate("hi(name)", knowledge2) == "hi?");
    vector<vector<string>> knowledge3 = {{"a", "yes"}};
    assert(s.evaluate("(a)(a)(a)aaa", knowledge3) == "yesyesyesaaa");
    return 0;
}
