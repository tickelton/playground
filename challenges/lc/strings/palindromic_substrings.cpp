/*

# Palindromic Substrings

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.


## Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".


## Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


## Constraints:

* 1 <= s.length <= 1000
* s consists of lowercase English letters.

*/

class Solution {
public:
    int countSubstrings(string s) {
        int ret = 0;

        for (int i=0; i<s.size(); ++i) {
            ++ret;
            for (int j=1; j<s.size(); ++j) {
                if (i-j < 0 || i + j >= s.size()) {
                    break;
                }
                if (s[i+j] != s[i-j]) {
                    break;
                }
                ++ret;
            }
        }
        if (s.size() > 1) {
            for (int i=0; i<s.size()-1; ++i) {
                if (s[i] != s[i+1]) {
                    continue;
                }
                ++ret;
                for (int j=1; j<s.size(); ++j) {
                    if (i-j < 0 || i + j + 1 >= s.size()) {
                        break;
                    }
                    if (s[i+j+1] != s[i-j]) {
                        break;
                    }
                    ++ret;
                }
            }
        }

        return ret;
    }
};
