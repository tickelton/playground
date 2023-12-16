/*

# Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


## Example 1:

Input: s = "anagram", t = "nagaram"
Output: true


## Example 2:

Input: s = "rat", t = "car"
Output: false


## Constraints:

* 1 <= s.length, t.length <= 5 * 10^4
* s and t consist of lowercase English letters.

*/

class Solution {
public:
/*
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
*/

    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        array<int, 26> sa = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        array<int, 26> ta = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

        for (int i=0;i<s.size(); ++i) {
            ++sa[s[i]-'a'];
            ++ta[t[i]-'a'];
        }

        return sa == ta;
    }
};
