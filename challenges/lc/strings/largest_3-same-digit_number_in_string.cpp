/*

# Largest 3-Same-Digit Number in String

You are given a string num representing a large integer. An integer is good if it meets the following conditions:

* It is a substring of num with length 3.
* It consists of only one unique digit.

Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:

* A substring is a contiguous sequence of characters within a string.
* There may be leading zeroes in num or a good integer.


## Example 1:

Input: num = "6777133339"
Output: "777"
Explanation: There are two distinct good integers: "777" and "333".
"777" is the largest, so we return "777".

## Example 2:

Input: num = "2300019"
Output: "000"
Explanation: "000" is the only good integer.

## Example 3:

Input: num = "42352338"
Output: ""
Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.


## Constraints:

* 3 <= num.length <= 1000
* num only consists of digits.

*/

class Solution {
public:
    string largestGoodInteger(string num) {
        int counter = 1;
        char cur = num[0];
        string lgi = "-1";
        for (int i=1; i<num.size(); ++i) {
            //cout << num[i] << " " << cur << " " << counter << "\n";
            if (num[i] == cur) {
                ++counter;
            } else {
                counter = 1;
                cur = num[i];
            }

            if (counter == 3) {
                int prev_lgi = stoi(lgi);
                string candidate = string(3, cur);
                int new_lgi = stoi(candidate);
                if (new_lgi > prev_lgi) {
                    lgi = candidate;
                }

                // shortcut, since 999 is the largest possible digit,
                // so we can stop if we encounter it.
                if (lgi == "999") { break; }

                counter = 1;
            }
        }
        if (lgi == "-1") {
            return "";
        }
        return lgi;
    }
};