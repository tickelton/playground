/*

# Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.


## Example 1:

  -----------
 | 1 | 3 | 1 |
  -----------
 | 1 | 5 | 1 |
  -----------
 | 4 | 2 | 1 |
  -----------

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.


## Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12


## Constraints:

* m == grid.length
* n == grid[i].length
* 1 <= m, n <= 200
* 0 <= grid[i][j] <= 200

*/

class Solution {
public:
    // recursion + memoziation
    vector<vector<int>> dp;

    int minPathSumFrom(int row, int col, vector<vector<int>>& grid) {
        if (row == grid.size()-1 && col == grid[0].size()-1 ) {
            return grid[row][col];
        }

        if (row == grid.size()-1) {
            if (dp[row][col+1] == 0) {
                dp[row][col+1] = minPathSumFrom(row, col+1, grid);
            }
            return grid[row][col] + dp[row][col+1];
        }

        if (col == grid[0].size()-1) {
            if (dp[row+1][col] == 0) {
                dp[row+1][col] = minPathSumFrom(row+1, col, grid);
            }
            return grid[row][col] + dp[row+1][col];
        }

        if (dp[row][col+1] == 0) {
            dp[row][col+1] = minPathSumFrom(row, col+1, grid);
        }
        if (dp[row+1][col] == 0) {
            dp[row+1][col] = minPathSumFrom(row+1, col, grid);
        }
        return grid[row][col] + min(
            dp[row][col+1],
            dp[row+1][col]
        );
    }

    int minPathSum(vector<vector<int>>& grid) {
        dp = vector(201, vector(201, 0));
        return minPathSumFrom(0, 0, grid);
    }
};
