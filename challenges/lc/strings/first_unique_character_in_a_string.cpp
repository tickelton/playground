/*

# First Unique Character in a String

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.


## Example 1:

Input: s = "leetcode"
Output: 0


## Example 2:

Input: s = "loveleetcode"
Output: 2


## Example 3:

Input: s = "aabb"
Output: -1


## Constraints:

* 1 <= s.length <= 10^5
* s consists of only lowercase English letters.

*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (char c:s) {
            if (m.contains(c)) {
                m[c]++;
            } else {
                m[c] = 1;
            }
        }

        for (int i=0; i<s.size(); ++i) {
            if (m[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
