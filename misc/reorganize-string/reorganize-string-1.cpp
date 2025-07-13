#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <string>

using namespace std;

// Recursive
// Time complexity: O(N * logN).
// Space complexity: O(N)
// N: string length

string reorganizeString(const string& s) {
  // Hash for the occurrence of the lowercase English letters.
  array<size_t, 26> occurrences{};
  
  // Count the occurrence of the lowercase English letters.
  for (const char c : s) {
    ++occurrences[c - 'a'];
  }

  // Get the most frequent letter occurrence.
  const size_t maxOccurrence = *max_element(occurrences.cbegin(), occurrences.cend());
  const size_t len = s.size();

  // Detect if reorganizing is not possible.
  if (maxOccurrence > (len + 1) / 2) return {};
   
  set<pair<int, size_t>, std::greater<pair<int, size_t>>> letterOccurrences;
  for (size_t i = 0; i < occurrences.size(); ++i) {
    if (occurrences[i]) letterOccurrences.insert({occurrences[i], i});
  }

  string result = s;
  // Start putting the most frequent letter at the first position in the result.
  size_t index = 0;
  for (auto [count, alphabetIndex] : letterOccurrences) {
      while (count--) {
          result[index] = 'a' + alphabetIndex;
          // Make sure that the same letters are not placed next to each other.
          index += 2;
          // If reaching the end of the result string, put letters in odd positions.
          if (index >= len) index = 1;
      }
  }

  return result;
}

int main()
{
    cout << reorganizeString("aab") << endl;
    cout << reorganizeString("aaab") << endl;

    return 0;
}
