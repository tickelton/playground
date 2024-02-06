/*

# Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


## Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]


## Example 2:

Input: strs = [""]
Output: [[""]]


## Example 3:

Input: strs = ["a"]
Output: [["a"]]


## Constraints:

* 1 <= strs.length <= 10^4
* 0 <= strs[i].length <= 100
* strs[i] consists of lowercase English letters.

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> ss(strs);
        for (int i=0; i<ss.size(); ++i) {
            sort(ss[i].begin(), ss[i].end());
        }

        unordered_map<string, vector<int>> m;
        for (int i=0; i<ss.size(); ++i) {
            if (m.contains(ss[i])) {
                m[ss[i]].push_back(i);
            } else {
                m[ss[i]] = {i};
            }
        }

        vector<vector<string>> ret;
        for (auto [k, v]: m) {
            vector<string> tmp;
            for (auto i: v) {
                tmp.push_back(strs[i]);
            }
            ret.emplace_back(tmp);
        }

        return ret;
    }
};
