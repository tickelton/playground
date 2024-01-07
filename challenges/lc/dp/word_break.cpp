/*

# Word Break

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.


## Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".


## Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.


## Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false


## Constraints:

* 1 <= s.length <= 300
* 1 <= wordDict.length <= 1000
* 1 <= wordDict[i].length <= 20
* s and wordDict[i] consist of only lowercase English letters.
* All the strings of wordDict are unique.

*/

class Solution {
public:
    unordered_map<string, bool> m;

    bool inDict(string s, vector<string>& wordDict) {
        for (const auto& w: wordDict) {
            if (s == w) {
                return true;
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[s.size()] = true;

        for (int i=s.size()-1; i>=0; --i) {
            for (int j=1; j<=20 && i+j<=s.size(); ++j) {
                if (i+j>s.size()) {
                    continue;
                }

                bool found = false;
                string ss = s.substr(i, j);
                if (m.find(ss) != m.end()) {
                    found = true;
                } else {
                    if (inDict(ss, wordDict)) {
                        m[ss] = true;
                        found = true;
                    }
                }
                if (found && dp[i+j]) {

                    dp[i] = true;
                }
            }
        }

        return dp[0];
    }
};
