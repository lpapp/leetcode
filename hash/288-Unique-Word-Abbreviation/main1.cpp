#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class ValidWordAbbr {
    unordered_map<string, unordered_set<string>> hash;
    string abbreviate(const string& word) { const size_t length = word.size(); if (length < 3) return word; return word.substr(0, 1) + to_string(length - 2) + word.substr(length - 1, 1); }
public:
    ValidWordAbbr(vector<string>& dictionary) { for (const string& word : dictionary) hash[abbreviate(word)].insert(word); }
    bool isUnique(string word) { const string abbreviation = abbreviate(word); return !hash.contains(abbreviation) || hash[abbreviation] == unordered_set{word}; }
};

int main()
{
    vector<string> dictionary1 = {"deer", "door", "cake", "card"};
    ValidWordAbbr* obj = new ValidWordAbbr(dictionary1);
    cout << obj->isUnique("dear") << endl;
    cout << obj->isUnique("cart") << endl;
    cout << obj->isUnique("cake") << endl;
    cout << obj->isUnique("door") << endl;
	return 0;
}
