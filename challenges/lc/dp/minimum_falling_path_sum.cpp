/*

# Minimum Falling Path Sum

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).


## Example 1:

  -----------
 | 2 | 1 | 3 |
  -----------
 | 6 | 5 | 4 |
  -----------
 | 7 | 8 | 9 |
  -----------

  -----------   -----------
 | x | 1 | x | | x | 1 | x |
  -----------   -----------
 | x | 5 | x | | x | x | 4 |
  -----------   -----------
 | 7 | x | x | | x | 8 | x |
  -----------   -----------

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

## Example 2:

  -------
 |-19| 57|
  -------
 |-40| -5|
  -------

  -------
 |-19| x |
  -------
 |-40| x |
  -------

Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.


## Constraints:

* n == matrix.length == matrix[i].length
* 1 <= n <= 100
* -100 <= matrix[i][j] <= 100

*/

class Solution {
public:
    int minFall(int row, int col, vector<vector<int>>& matrix) {
        int minval = matrix[row][col];
        if (col>0 && matrix[row][col-1] < minval) {
            minval = matrix[row][col-1];
        }
        if (col<matrix.size()-1 && matrix[row][col+1] < minval) {
            minval = matrix[row][col+1];
        }
        return minval;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector(matrix.size(), 0));

        for (int row=matrix.size()-1; row >=0; --row) {
            for (int col=0; col<matrix.size(); ++col) {
                if (row == matrix.size()-1) {
                    dp[row][col] = matrix[row][col];
                } else {
                    dp[row][col] =  matrix[row][col] + minFall(row+1, col, dp);
                }
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};
