/*

# Difference Between Ones and Zeros in Row and Column

You are given a 0-indexed m x n binary matrix grid.

A 0-indexed m x n difference matrix diff is created with the following procedure:

* Let the number of ones in the ith row be onesRow(i).
* Let the number of ones in the jth column be onesCol(j).
* Let the number of zeros in the ith row be zerosRow(i).
* Let the number of zeros in the jth column be zerosCol(j).
* diff[i][j] = onesRow(i) + onesCol(j) - zerosRow(i) - zerosCol(j)

Return the difference matrix diff.


## Example 1:

  -----------    -----------
 | 0 | 1 | 1 |  | 0 | 0 | 4 |
  -----------    -----------
 | 1 | 0 | 1 |  | 0 | 0 | 4 |
  -----------    -----------
 | 0 | 0 | 1 |  | -2| -2| 2 |
  -----------    -----------

Input: grid = [[0,1,1],[1,0,1],[0,0,1]]
Output: [[0,0,4],[0,0,4],[-2,-2,2]]
Explanation:
- diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 2 + 1 - 1 - 2 = 0
- diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 2 + 1 - 1 - 2 = 0
- diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 2 + 3 - 1 - 0 = 4
- diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 2 + 1 - 1 - 2 = 0
- diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 2 + 1 - 1 - 2 = 0
- diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 2 + 3 - 1 - 0 = 4
- diff[2][0] = onesRow2 + onesCol0 - zerosRow2 - zerosCol0 = 1 + 1 - 2 - 2 = -2
- diff[2][1] = onesRow2 + onesCol1 - zerosRow2 - zerosCol1 = 1 + 1 - 2 - 2 = -2
- diff[2][2] = onesRow2 + onesCol2 - zerosRow2 - zerosCol2 = 1 + 3 - 2 - 0 = 2


## Example 2:

  -----------    -----------
 | 1 | 1 | 1 |  | 5 | 5 | 5 |
  -----------    -----------
 | 1 | 1 | 1 |  | 5 | 5 | 5 |
  -----------    -----------

Input: grid = [[1,1,1],[1,1,1]]
Output: [[5,5,5],[5,5,5]]
Explanation:
- diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 3 + 2 - 0 - 0 = 5
- diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 3 + 2 - 0 - 0 = 5
- diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 3 + 2 - 0 - 0 = 5
- diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 3 + 2 - 0 - 0 = 5
- diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 3 + 2 - 0 - 0 = 5
- diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 3 + 2 - 0 - 0 = 5


## Constraints:

* m == grid.length
* n == grid[i].length
* 1 <= m, n <= 10^5
* 1 <= m * n <= 10^5
* grid[i][j] is either 0 or 1.


*/

class Solution {
public:
/*
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> onesRow;
        vector<int> onesCol;

        for (int row=0; row<grid.size(); ++row) {
            int ones = 0;
            for (int i: grid[row]) {
                if (i == 1) { ++ones; }
            }
            onesRow.push_back(ones);
        }

        for (int col=0; col<grid[0].size(); ++col) {
            int ones = 0;
            for (int row=0; row<grid.size(); ++row) {
                if (grid[row][col] == 1) { ++ones; }
            }
            onesCol.push_back(ones);
        }

        vector<int> absRow;
        for (int row=0; row<grid.size(); ++row) {
            absRow.push_back(
                onesRow[row] - (grid[0].size()-onesRow[row])
            );
        }

        vector<int> absCol;
        for (int col=0; col<grid[0].size(); ++col) {
            absCol.push_back(
                onesCol[col] - (grid.size()-onesCol[col])
            );
        }

        vector<vector<int>> ret;
        for (int row=0; row<grid.size(); ++row) {
            vector<int> diffRow;
            for (int col=0; col<grid[0].size(); ++col) {
                diffRow.push_back(
                    absRow[row] + absCol[col]
                );
            }
            ret.push_back(diffRow);
        }

        return ret;
    }
*/

    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> absRow(m, 0);
        vector<int> absCol(n, 0);

        for (int row=0; row<m; ++row) {
            for (int col=0; col<n; ++col) {
                if (grid[row][col] == 1) {
                    ++absRow[row];
                    ++absCol[col];
                } else {
                    --absRow[row];
                    --absCol[col];
                }
            }
        }

        vector<vector<int>> ret(m, vector<int>(n, 0));
        for (int row=0; row<grid.size(); ++row) {
            for (int col=0; col<grid[0].size(); ++col) {
                    ret[row][col] = absRow[row] + absCol[col];
            }
        }

        return ret;
    }

};
