/*

# Number of Dice Rolls With Target Sum

You have n dice, and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the k^n total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.


## Example 1:

Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.


## Example 2:

Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.


## Example 3:

Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.


## Constraints:

* 1 <= n, k <= 30
* 1 <= target <= 1000

*/

class Solution {
public:

    const int MOD = 1000000007;
    vector<vector<int>> dp;
    int solveRolls(int n, int k, int target) {
        if (n == 0 && target == 0) { return 1; }
        if (target < n || n*k < target) {
            return 0;
        }
        if (dp[n][target] != 0) {
            return dp[n][target];
        }

        long long ret = 0;
        for (int i=1; i<=k; ++i) {
            if (target - i < 0) { break; }

            ret = (ret + solveRolls(n-1, k, target-i) % MOD) % MOD;
        }
        dp[n][target] = ret;
        return ret;
    }

    int numRollsToTarget(int n, int k, int target) {
        //cout << "n= " << n << " k=" << k << " target=" << target << "\n";
        if (n == 0 && target == 0) { return 1; }
        /*
        if (n == 1) {
            if (target <= k) {
                return 1;
            } else {
                return 0;
            }
        }
        */
        if (target < n || n*k < target) {
            return 0;
        }

        dp = vector(n+1, vector(target+1, 0));
        return solveRolls(n, k, target);

    }

};
