/*

Unique Paths

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 10^ 9.


## Example 1:

  -------------------------------------------------------
 |       |       |       |       |       |       |       |
 | start |       |       |       |       |       |       |
 |       |       |       |       |       |       |       |
  -------------------------------------------------------
 |       |       |       |       |       |       |       |
 |       |       |       |       |       |       |       |
 |       |       |       |       |       |       |       |
  -------------------------------------------------------
 |       |       |       |       |       |       |       |
 |       |       |       |       |       |       |  end  |
 |       |       |       |       |       |       |       |
  -------------------------------------------------------

Input: m = 3, n = 7
Output: 28


## Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down


## Constraints:

* 1 <= m, n <= 100

*/

class Solution {
public:
    // recursion + memoization
    bool initialized = false;
    vector<vector<int>> dp;

    int uniquePaths(int m, int n) {
        if (m==1 && n==1) {
            return 1;
        }

        if (!initialized) {
            dp = vector(101, vector(101, -1));
            initialized = true;
        }

        if (m==1) {
            if (dp[m][n-1] == -1) {
                dp[m][n-1] = uniquePaths(m, n-1);
            }
            return dp[m][n-1];
        }
        if (n==1) {
            if (dp[m-1][n] == -1) {
                dp[m-1][n] = uniquePaths(m-1, n);
            }
            return dp[m-1][n];
        }

        if (dp[m][n-1] == -1) {
            dp[m][n-1] = uniquePaths(m, n-1);
        }
        if (dp[m-1][n] == -1) {
            dp[m-1][n] = uniquePaths(m-1, n);
        }
        return dp[m][n-1] + dp[m-1][n];
    }
};
