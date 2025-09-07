#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class HtmlParser {
	public:
		vector<string> getUrls(string url) { return {url}; }
};

class Solution {
    string extractHostname(const string& url) {
        static constexpr size_t protocolLength = 7;
        string hostname;
        for (size_t i = protocolLength; i < url.size(); ++i) {
            if (url[i] == '/') break;
            hostname += url[i];
        }
        return hostname;
    }

	void dfs(const string& url, HtmlParser& htmlParser, 
    	unordered_set<string>& visited, vector<string>& result) {
        if (visited.contains(url)) return;
        visited.insert(url);
        result.push_back(url);
        for (const string& nextUrl : htmlParser.getUrls(url)) {
            if (extractHostname(url) == extractHostname(nextUrl))
                dfs(nextUrl, htmlParser, visited, result);
        }
    }

public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        vector<string> result;
        unordered_set<string> visited;
        dfs(startUrl, htmlParser, visited, result);
        return result;
    }
};

int main()
{
	Solution s;
    HtmlParser htmlParser;
    s.crawl("http://foo.com/test", htmlParser);
	return 0;
}
