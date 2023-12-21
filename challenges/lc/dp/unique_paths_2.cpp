/*

# Unique Paths II

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 10^9.


## Example 1:

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right


## Example 2:

Input: obstacleGrid = [[0,1],[0,0]]
Output: 1


## Constraints:

* m == obstacleGrid.length
* n == obstacleGrid[i].length
* 1 <= m, n <= 100
* obstacleGrid[i][j] is 0 or 1.

*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(100, vector(100, 0));

        for (int row = obstacleGrid.size()-1; row >= 0; --row) {
            for (int col = obstacleGrid[0].size()-1; col >= 0; --col) {
                if (row == obstacleGrid.size()-1 && col == obstacleGrid[0].size() -1) {
                    if (obstacleGrid[row][col] == 1) {
                        return 0;
                    } else {
                        dp[row][col] = 1;
                    }
                } else if (row == obstacleGrid.size()-1) {
                    if (obstacleGrid[row][col] == 1 ||  dp[row][col+1] == 0) {
                        dp[row][col] = 0;
                    } else {
                        dp[row][col] = dp[row][col+1];
                    }
                } else if (col == obstacleGrid[0].size()-1) {
                    if (obstacleGrid[row][col] == 1 ||  dp[row+1][col] == 0) {
                        dp[row][col] = 0;
                    } else {
                        dp[row][col] = dp[row+1][col];
                    }
                } else {
                    if (obstacleGrid[row][col] == 1) {
                        dp[row][col] = 0;
                    } else if (dp[row+1][col] == 0 && dp[row][col+1] != 0){
                        dp[row][col] = dp[row][col+1];
                    } else if (dp[row][col+1] == 0 && dp[row+1][col] != 0){
                        dp[row][col] = dp[row+1][col];
                    } else {
                        // Intermediate results might overflow unsigned int, but
                        // the return value of the function is guaranteed to always
                        // fit in an int.
                        // We could have the case that and intermediate value
                        // is > 2^32, but later there's an obstacle in the way so
                        // we won't use that value.
                        // A cleaner solution would be to track intermediate values
                        // as long long.
                        // And as an optimization we could check for signed int
                        // overflow and just return 0 in that case because there
                        // won't be a path to the target.
                        unsigned int tmp = (unsigned int)dp[row+1][col] + (unsigned int)dp[row][col+1];
                        dp[row][col] = (int)tmp;
                    }
                }
            }
        }

        return dp[0][0];
    }
};
