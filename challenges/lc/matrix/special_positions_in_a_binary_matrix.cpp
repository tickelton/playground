/*

# Special Positions in a Binary Matrix

Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).


## Example 1:

  -----------
 | 1 | 0 | 0 |
  -----------
 | 0 | 0 | 1 |
  -----------
 | 1 | 0 | 0 |
  -----------

Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.


## Example 2:

  -----------
 | 1 | 0 | 0 |
  -----------
 | 0 | 1 | 0 |
  -----------
 | 0 | 0 | 1 |
  -----------

Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Explanation: (0, 0), (1, 1) and (2, 2) are special positions.


## Constraints:

* m == mat.length
* n == mat[i].length
* 1 <= m, n <= 100
* mat[i][j] is either 0 or 1.

*/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int special_positions = 0;
        for (int row=0; row<mat.size(); ++row) {
            for (int col=0; col<mat[0].size(); ++col) {
                if (mat[row][col] == 0) {
                    continue;
                }
                bool unique = true;
                for (int i=col+1; i<mat[0].size(); ++i) {
                    if (mat[row][i] != 0) {
                        unique = false;
                        break;
                    }
                }
                if (!unique) { break; }
                // 1 is unique in this row; check column
                unique = true;
                for (int i=0; i<mat.size(); ++i) {
                    if (mat[i][col] != 0 && i != row) {
                        unique = false;
                        break;
                    }
                }
                if (unique) {
                    ++special_positions;
                }
                break;
            }
        }

        return special_positions;
    }
};
