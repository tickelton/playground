/*

# Fibonacci Number

The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.

Given n, calculate F(n).


## Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

## Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

## Example 3:

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.


## Constraints:

* 0 <= n <= 30

*/

class Solution {
public:
    // recursion + memoization
    /*
    array<int, 31> dp = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    int fib(int n) {
        if (n == 0) { return 0; }
        if (n == 1) { return 1; }

        if (dp[n-1] == -1) {
            dp[n-1] = fib(n-1);
        }
        if (dp[n-2] == -1) {
            dp[n-2] = fib(n-2);
        }
        return dp[n-1] + dp[n-2];
    }
    */

    // iterative tabulation
    int fib(int n) {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);

        for (int i=2; i<=n; ++i) {
            dp.push_back(dp[i-1] + dp[i-2]);
        }

        return dp[n];
    }
};
