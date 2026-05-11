#include <cassert>
#include <deque>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        deque<string> s;
        stringstream pathStream(path);
        string token;
        while (getline(pathStream, token, '/')) {
            if (token == "" || token == ".") continue;
            if (token == "..") { if (!s.empty()) s.pop_back(); }
            else s.push_back(token);
        }
        if (s.empty()) return "/";
        string res;
        for (const auto& dir : s) res += "/" + dir;
        return res;
    }
};

int main()
{
	Solution s;
	assert(s.simplifyPath("/home/") == "/home");
	assert(s.simplifyPath("/home//foo/") == "/home/foo");
	assert(s.simplifyPath("/home/user/Documents/../Pictures") == "/home/user/Pictures");
	assert(s.simplifyPath("/../") == "/");
	assert(s.simplifyPath("/.../a/../b/c/../d/./") == "/.../b/d");
	return 0;
}
