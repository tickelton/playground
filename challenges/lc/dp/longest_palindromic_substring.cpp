/*

# Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.


## Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.


## Example 2:

Input: s = "cbbd"
Output: "bb"


## Constraints:

* 1 <= s.length <= 1000
* s consist of only digits and English letters.

*/

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector(s.size(), false));

        array<int, 2> ans = {0, 0};
        for (int i=0; i<s.size(); ++i) {
                dp[i][i] = true;
        }

        for (int i=0; i<s.size()-1; ++i) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                ans[0] = i;
                ans[1] = i+1;
            }
        }

        for (int diff=2; diff<s.size(); ++diff) {
            for (int i=0; i<s.size()-diff; ++i) {
                int j = i + diff;
                if (dp[i+1][j-1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }

        return s.substr(ans[0], ans[1]-ans[0]+1);
    }
};
