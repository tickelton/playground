/*

#Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".

A common subsequence of two strings is a subsequence that is common to both strings.


## Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.


## Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.


## Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.


## Constraints:

* 1 <= text1.length, text2.length <= 1000
* text1 and text2 consist of only lowercase English characters.

*/

class Solution {
public:
/*
  a a e
a 1 1 1 
b 1 1 1
a 1 2 2
c 1 2 2
d 1 2 2
e 1 2 3

  a c e
a 1 1 1
b 1 1 1
c 1 2 2
d 1 2 2
e 1 2 3

  y b y
b 0 1 1
l 0 0 1
*/
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector(text2.size(), 0));

        for (int i = 0; i<text1.size(); ++i) {
            for (int j = 0; j<text2.size(); ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = text1[i] == text2[j] ? 1 : 0;

                } else if (j == 0) {
                    dp[i][j] = text1[i] == text2[j] ? 1 : dp[i-1][j];
                } else if (i == 0) {
                    dp[i][j] = text1[i] == text2[j] ? 1 : dp[i][j-1];
                } else {
                    if (text1[i] == text2[j]) {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    } else {
                        dp[i][j] = max(
                            dp[i][j-1],
                            dp[i-1][j]
                        );
                    }
                }
            }
        }
        
        return dp[text1.size()-1][text2.size()-1];
    }
};
