/*

# Apply Operations to Make String Empty

You are given a string s.

Consider performing the following operation until s becomes empty:

* For every alphabet character from 'a' to 'z', remove the first occurrence of that character in s (if it exists).

Return the value of the string s right before applying the last operation.


## Example 1:

Input: s = "aabcbbca"
Output: "ba"
Explanation: We do the following operations:
- Remove the underlined characters s = "aabcbbca". The resulting string is s = "abbca".
- Remove the underlined characters s = "abbca". The resulting string is s = "ba".
- Remove the underlined characters s = "ba". The resulting string is s = "".
The string just before the last operation is "ba".


## Example 2:

Input: s = "abcd"
Output: "abcd"
Explanation: We do the following operation:
- Remove the underlined characters s = "abcd". The resulting string is s = "".
The string just before the last operation is "abcd".


## Constraints:

* 1 <= s.length <= 5 * 10^5
* s consists only of lowercase English letters.

*/

class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char, int> m;
        int maxval = 0;
        for (auto c: s) {
            if (m.contains(c)) {
                m[c]++;
            } else {
                m[c] = 1;
            }
            if (m[c] > maxval) {
                maxval = m[c];
            }
        }
        
        string ret;
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            if (m[*it] == maxval) {
                ret.push_back(*it);
                m[*it]--;
            }
        }
        
        int n = ret.length();
 
        for (int i = 0; i < n / 2; i++) {
            swap(ret[i], ret[n - i - 1]);
        }
        return ret;
    }
};
