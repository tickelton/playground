/*

# Determine if Two Strings Are Close

Two strings are considered close if you can attain one from the other using the following operations:

* Operation 1: Swap any two existing characters.
    For example, abcde -> aecdb
* Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
    For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)

You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.


## Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"


## Example 2:

Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.


## Example 3:

Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"


## Constraints:

* 1 <= word1.length, word2.length <= 10^5
* word1 and word2 contain only lowercase English letters.

*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> m1, m2;
        set<char> s1,s2;
        for (auto c: word1) {
            if (m1.find(c) != m1.end()) {
                ++m1[c];
            } else {
                m1[c] = 1;
            }
            s1.insert(c);
        }
        for (auto c: word2) {
            if (m2.find(c) != m2.end()) {
                ++m2[c];
            } else {
                m2[c] = 1;
            }
            s2.insert(c);
        }

        vector<int> v1, v2;
        for (auto e: m1) {
            v1.push_back(e.second);
        }
        for (auto e: m2) {
            v2.push_back(e.second);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        return v1 == v2 && s1 == s2;
    }
};
