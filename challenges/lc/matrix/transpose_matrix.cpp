/*

# Transpose Matrix

Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

  -----------        -----------
 | 2 | 4 | -1|      | 2 |-10| 18|
  -----------        -----------
 |-10| 5 | 11|  =>  | 4 | 5 | -7|
  -----------        -----------
 | 18| -7| 6 |      | -1| 11| 6 |
  -----------        -----------


## Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]


## Example 2:

Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]


## Constraints:

* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 1000
* 1 <= m * n <= 10^5
* -10^9 <= matrix[i][j] <= 10^9

*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ret;
        if (matrix.empty()) {
            return ret;
        }

        for (int col=0; col<matrix[0].size(); ++col) {
            vector<int> tmp;
            for (int row=0; row<matrix.size(); ++row) {
                tmp.push_back(matrix[row][col]);
            }
            ret.push_back(tmp);
        }

        return ret;
    }
};
