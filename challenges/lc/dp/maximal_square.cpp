/*

# Maximal Square

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.


## Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4


## Example 2:

Input: matrix = [["0","1"],["1","0"]]
Output: 1


## Example 3:

Input: matrix = [["0"]]
Output: 0


## Constraints:

* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 300
* matrix[i][j] is '0' or '1'.

*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp = vector(matrix.size(), vector(matrix[0].size(), 0));

        int max_area = 0;
        for (int row=matrix.size()-1; row >=0; --row) {
            for (int col=matrix[0].size()-1; col>=0; --col) {
                if (row==matrix.size()-1) {
                    dp[row][col] = matrix[row][col] == '0' ? 0 : 1;
                    if (dp[row][col] > max_area) {
                        max_area = dp[row][col];
                    }
                } else {
                    if (matrix[row][col] == '0') {
                        dp[row][col] = 0;
                    } else if (col<matrix[0].size()-1 && dp[row+1][col+1] != 0) {
                        int base = sqrt(dp[row+1][col+1]) + 1;
                        int max_base = 1;
                        for (int i=1; i<base; ++i) {
                            if (matrix[row+i][col] == '1' && matrix[row][col+i] == '1') {
                                ++max_base;
                            } else {
                                break;
                            }
                        }
                        dp[row][col] = max_base * max_base;
                    } else {
                        dp[row][col] = 1;
                    }
                    if (dp[row][col] > max_area) {
                        max_area = dp[row][col];
                    }
                }
            }
        }
        return max_area;
    }
};
