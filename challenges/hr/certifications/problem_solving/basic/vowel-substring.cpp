/*

# Vowel-Substring

Given a string of lowercase English letters and an integer of the substring length, determine the substring of that length that contains the most vowels. Vowels are in the set {a, e, i, o, u}. If there is more than one substring with the maximum number of vowels, return the one that starts at the lowest index. If there are no vowels in the input string, return the string 'Not found!' without quotes.


## Example 1

s = 'caberqiitefg'
k = 5

The substring of length k = 5 that contains the maximum number of vowels is 'erqii' with 3 vowels.

The final answer is 'erqii'.


## Example 2

s = 'aeiouia'
k = 3

All of the characters are vowels, so any substring of length 3 will have 3 vowels. The lowest index substring is at index 0, 'aei'.


## Function Description

Complete the function findSubstring in the editor below.

findSubstring has the following parameters:

* s: a string
* k: an integer

Returns:

* string:a string containing the final answer


## Constraints

* 1 ≤ length(s) ≤ 2 * 10^5
* 1 ≤ k ≤ length(s)


## Input Format For Custom Testing

The first line contains a string, s.
The second line contains an integer, k.


## Sample Case 0

### Sample Input

STDIN      Function
-----      -----
azerdii →  s = 'azerdii'
5       →  k = 5

### Sample Output

erdii

### Explanation

s = 'azerdii'
k = 5

The possible 5 character substrings are:

* 'azerd' which contains 2 vowels
* 'zerdi' which contains 2 vowels
* 'erdii' which contains 3 vowels

The final answer is 'erdii'.


## Sample Case 1

### Sample Input


STDIN     Function
-----     -----
qwdftr →  s = 'qwdftr'
2      →  k = 2

### Sample Output

Not found!

### Explanation

The given string does not contain any vowels, so 'Not Found!' is returned.

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findSubstring' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

bool is_vowel(char c) {
    if (c == 'a' ||
        c == 'e' ||
        c == 'i' ||
        c == 'o' ||
        c == 'u') {
            return true;
        }

    return false;
}

string findSubstring(string s, int k) {
    vector<int> res;

    for (int i=0; i<s.size(); ++i) {
        res.push_back(0);
    }

    int start_idx=-k+1;
    int end_idx=0;

    for (int i=0; i<s.size(); ++i) {
        if (is_vowel(s[i])) {
            for (int j=start_idx; j<=end_idx; ++j) {
                if (j >=0 && j<s.size()) {
                    res[j]++;
                }
            }
        }
        ++start_idx;
        ++end_idx;
    }

    vector<int>::iterator maxval = max_element(res.begin(), res.end());
    int max_idx =  distance(res.begin(), maxval);

    if (*maxval < 1) { return "Not found!"; }

    string ret;
    for (int i=0; i<k; ++i) {
        ret.push_back(s[max_idx+i]);
    }


    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = findSubstring(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
