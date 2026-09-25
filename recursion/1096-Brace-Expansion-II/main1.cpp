#include <cassert>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
    string e;
    int pos = 0;

    set<string> parseExpr() {                    // union: term (',' term)*
        set<string> res = parseTerm();
        while (pos < (int)e.size() && e[pos] == ',') {
            ++pos;
            for (const string& w : parseTerm()) res.insert(w);
        }
        return res;
    }

    set<string> parseTerm() {                    // concat: factor factor*
        set<string> res{""};
        while (pos < (int)e.size() && e[pos] != ',' && e[pos] != '}') {
            const set<string> f = parseFactor();
            set<string> next;
            for (const string& a : res)
                for (const string& b : f) next.insert(a + b);
            res = std::move(next);
        }
        return res;
    }

    set<string> parseFactor() {                  // letter | '{' expr '}'
        if (e[pos] == '{') {
            ++pos;
            set<string> res = parseExpr();
            ++pos;
            return res;
        }
        return {string(1, e[pos++])};
    }

public:
    vector<string> braceExpansionII(string expression) {
        e = std::move(expression);
        pos = 0;
        const set<string> result = parseExpr();
        return {result.begin(), result.end()};
    }
};

int main()
{
    Solution s;
    vector<string> res1 = {"ac", "ad", "ae", "bc", "bd", "be"};
    assert(s.braceExpansionII("{a,b}{c,{d,e}}") == res1);
    vector<string> res2 = {"a", "ab", "ac", "z"};
    assert(s.braceExpansionII("{{a,z},a{b,c},{ab,z}}") == res2);
    return 0;
}
