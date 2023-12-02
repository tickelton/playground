/*

# Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


## Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

## Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


## Constraints:

* 1 <= n <= 45

*/


class Solution {
public:
// recursive approach without memoization
/*
    public:
    int climbStairs(int n) {
        if (n==0) { return 0; }
        if (n==1) { return 1; }
        if (n==2) { return 2; }

        return climbStairs(n-1) + climbStairs(n-2);
    }
*/

// top down DP approach: recursion + memoization
/*
    unordered_map<int, int> ways;
    int climbStairs(int n) {
        if (n==0) { return 0; }
        if (n==1) { return 1; }
        if (n==2) { return 2; }

        if (ways.find(n) != ways.end()) {
            return ways[n];
        }

        ways[n] = climbStairs(n-1) + climbStairs(n-2);

        return ways[n];
    }
*/

// bottom up DP approach: iterative tabulation
/*
    int climbStairs(int n) {
        vector<int> dp;

        dp.push_back(0);
        dp.push_back(1);
        dp.push_back(2);
        for (int i=3; i<=n; ++i) {
            dp.push_back(
                dp[i-1] + dp[i-2]
            );
        }

        return dp[n];
    }
*/

// bottom up DP approach with manual memory allocation
/*
    int climbStairs(int n) {
        if (n<3) { return n; };

        int *dp;
        dp = new int[n+1];

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i=3; i<=n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        int ret = dp[n];
        delete [] dp;

        return dp[n];
    }
*/

// bottom up DP approach; runtime and memory optimized
    int climbStairs(int n) {
        if (n<3) { return n; };

        int dp0 = 1;
        int dp1 = 2;

        for (int i=3; i<=n; ++i) {
            int ndp = dp0 + dp1;
            dp0 = dp1;
            dp1 = ndp;
        }

        return dp1;
    }
};
