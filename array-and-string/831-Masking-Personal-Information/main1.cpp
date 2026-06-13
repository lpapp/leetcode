#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    string maskPII(string s) {
    	const size_t at = s.find('@');
    	if (at != string::npos) { string res; res.reserve(7 + s.size() - at); res += tolower(s[0]); res += "*****"; res.append(s, at - 1); std::transform(res.begin() + 6, res.end(), res.begin() + 6, ::tolower); return res; }
    	int cnt = 0;
    	char tail[4];
    	for (int i = s.size() - 1, pos = 3; i >= 0; --i) { if (isdigit(s[i])) { if (pos >= 0) tail[pos--] = s[i]; ++cnt; } }
    	string res;
    	int cc = cnt - 10;
    	if (cc > 0) { res.reserve(cc + 14); res += '+'; res.append(cc, '*'); res += '-'; }
        else res.reserve(12);
    	res += "***-***-";
    	res.append(tail, 4);
    	return res;
    }
};

int main()
{
    Solution s;
    assert(s.maskPII("LeetCode@LeetCode.com") == "l*****e@leetcode.com");
    assert(s.maskPII("AB@qq.com") == "a*****b@qq.com");
    assert(s.maskPII("1(234)567-890") == "***-***-7890");
    assert(s.maskPII("86-(10)12345678") == "+**-***-***-5678");
    return 0;
}
