/*

# Maximum Length of a Concatenated String with Unique Characters

You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.


## Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.


## Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").


## Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.


## Constraints:

* 1 <= arr.length <= 16
* 1 <= arr[i].length <= 26
* arr[i] contains only lowercase English letters.

*/

class Solution {
public:
    int to_bits(const string& s) {
        int ret = 0;
        int dup = 0;
        for (auto c: s) {
            dup |= ret & (1<<(c-'a'));
            ret |= (1<<(c-'a'));
        }
        if (dup) { return 0; }
        return ret;
    }

    int count_bits(int data) {
        int ret = 0;
        for (int i=0; i<32; ++i) {
            if (data & 1<<i) {
                ++ret;
            }
        }
        return ret;
    }

    int maxLength(vector<string>& arr) {
        vector<int> dp(1, 0);
        int ret = 0;

        for (const auto& s: arr) {
            int bits = to_bits(s);
            if (!bits) { continue; }

            for (int i=0; i<dp.size(); ++i) {
                if (dp[i] & bits) {
                    continue;
                }
                dp.push_back(dp[i] | bits);
                ret = max(
                    ret,
                    count_bits(dp[i] | bits)
                );
            }
        }

        return ret;
    }
};
