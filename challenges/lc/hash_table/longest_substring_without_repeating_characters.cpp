/*

# Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.


## Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.


## Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.


## Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


## Constraints:

* 0 <= s.length <= 5 * 10^4
* s consists of English letters, digits, symbols and spaces.

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2) { return s.size(); }

        unordered_map<char, int> m;
        int left = 0;
        int right = 0;
        int len = 1;
        int curlen = 0;

        while (right < s.size()) {
            if (m.find(s[right]) == m.end()) {
                m[s[right]] = 1;
                ++curlen;
            } else if (m[s[right]] == 0) {
                m[s[right]] = 1;
                ++curlen;
            } else {
                while (m[s[right]] > 0) {
                    --m[s[left]];
                    ++left;
                    --curlen;
                }
                m[s[right]] = 1;
                ++curlen;
            }
            if (curlen > len) {
                len = curlen;
            }
            ++right;
        }

        return len;
    }
};
