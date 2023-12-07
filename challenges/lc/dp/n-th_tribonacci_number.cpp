/*

# N-th Tribonacci Number


The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.


## Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4


## Example 2:

Input: n = 25
Output: 1389537


## Constraints:

* 0 <= n <= 37
* The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.

*/

class Solution {
public:
    // recursion + memoziation
    /*
    array<int, 38> dp = {0, 1, 1};
    int tribonacci(int n) {
        if (n == 0) { return 0; }
        if (n == 1) { return 1; }
        if (n == 2) { return 1; }

        if (dp[n] == 0) {
          dp[n] = tribonacci(n-1) +
                  tribonacci(n-2) +
                  tribonacci(n-3);
        }

        return dp[n];
    }
    */

    // iterative tabulation
    /*
    int tribonacci(int n) {
      vector<int> dp = {0, 1, 1};

      for (int i=3; i<=n; ++i) {
        dp.push_back(dp[i-1] + dp[i-2] + dp[i-3]);
      }

      return dp[n];
    }
    */

    // iterative tabulation; storage optimized
    int tribonacci(int n) {
      array<int, 3> dp = {0, 1, 1};

      if (n < 3) { return dp[n]; }

      for (int i=3; i<=n; ++i) {
        int tmp = dp[2];
        dp[2] = dp[2] + dp[1] + dp[0];
        dp[0] = dp[1];
        dp[1] = tmp;
      }

      return dp[2];
    }
};
