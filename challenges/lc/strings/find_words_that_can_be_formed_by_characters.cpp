/*
# Find Words That Can Be Formed by Characters

You are given an array of strings words and a string chars.
A string is good if it can be formed by characters from chars (each character can only be used once).
Return the sum of lengths of all good strings in words.


## Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

## Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.


## Constraints:

* 1 <= words.length <= 1000
* 1 <= words[i].length, chars.length <= 100
* words[i] and chars consist of lowercase English letters.

*/

class Solution {
public:
  int countCharacters(vector<string>& words, string chars) {
    unordered_map<char, int> chars_map;
    for (const auto c: chars) {
      if (chars_map.find(c) != chars_map.end()) {
        chars_map[c]++;
      } else {
        chars_map[c] = 1;
      }
    }

    int ret = 0;
    for (const auto &w: words) {
      unordered_map<char, int> word_map;
      for (const auto c: w) {
        if (word_map.find(c) != word_map.end()) {
          word_map[c]++;
        } else {
          word_map[c] = 1;
        }
      }

      bool fail = false;
      for (auto const &i: word_map) {
        if (word_map.find(i.first) != word_map.end()) {
          if (i.second > chars_map[i.first]) {
            fail = true;
              break;
          }
        } else {
          fail = true;
          break;
        }
      }
      if (fail) { continue; }
      ret += w.size();
    }

    return ret;
  }
};
